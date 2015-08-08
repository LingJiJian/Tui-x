/************************************************************************
The MIT License(MIT)

Copyright(c) 2014 Lingjijian [B-y]

342854406@qq.com

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files(the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and / or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions :

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
************************************************************************/
#include "MapView.h"

NS_CC_WIDGET_BEGIN

CMapGrid* CMapGrid::create( int numCols,int numRows )
{
	CMapGrid *ret = new CMapGrid();
	if (ret && ret->init(numCols,numRows))
	{
		ret->autorelease();
		return ret;
	}
	CC_SAFE_DELETE(ret);
	return NULL;
}

bool CMapGrid::init( int numCols,int numRows )
{
	_numCols = numCols;
	_numRows = numRows;
	_startNode = nullptr;
	_endNode = nullptr;
	
	_nodes = vector<VectNode>();
	for (int i = 0;i< _numCols; i++)
	{
		_nodes.push_back(VectNode());
		for (int j = 0;j< _numRows; j++)
		{
			_nodes[i].pushBack( CGridNode::create(i,j) );
		}
	}
	return true;
}

void CMapGrid::setStartNode( int x,int y )
{
	auto node = _nodes[x].at(y);
	if (_startNode != node) 
	{ 
		CC_SAFE_RETAIN(node); 
		CC_SAFE_RELEASE(_startNode); 
		_startNode = node; 
	} 
}

void CMapGrid::setEndNode( int x,int y )
{
	auto node = _nodes[x].at(y);
	if (_endNode != node) 
	{ 
		CC_SAFE_RETAIN(node); 
		CC_SAFE_RELEASE(_endNode); 
		_endNode = node; 
	} 
}

CGridNode* CGridNode::create( int x,int y )
{
	CGridNode *ret = new CGridNode();
	if (ret && ret->init(x,y))
	{
		ret->autorelease();
		return ret;
	}
	CC_SAFE_DELETE(ret);
	return NULL;
}

bool CGridNode::init( int x,int y )
{
	this->x = x;
	this->y = y;
	this->costMultiplier = 1;
    this->walkable = true;
	return true;
}

static AStar* s_Astar = nullptr;
AStar* AStar::getInstance()
{
	if (s_Astar == nullptr)
	{
		s_Astar = new (std::nothrow) AStar();
		if(s_Astar && s_Astar->init()){
			s_Astar->retain();
		}else{
			CC_SAFE_DELETE(s_Astar);
			s_Astar = nullptr;
		}
	}
	return s_Astar;
}

bool AStar::init()
{
	_startNode = nullptr;
	_endNode = nullptr;
	setHeuristicFunc(eManhattan);
	return true;
}

bool AStar::findPath( CMapGrid *grid )
{
	_grid = grid;
	_open = VectNode();
	_close = VectNode();
	_startNode = _grid->getStartNode();
	_endNode = _grid->getEndNode();
	_startNode->g = 0;
	_startNode->h = _heuristic(_startNode);

	return search();
}

bool AStar::search()
{
	auto node = _startNode;
	while (node != _endNode)
	{
		int startX = max(0, node->x - 1);
		int endX = min(_grid->getNumCols() - 1, node->x + 1);
		int startY = max(0, node->y - 1);
		int endY = min(_grid->getNumRows() - 1,node->y + 1);

		for (int i = startX;i<= endX;i ++)
		{
			for (int j = startY;j<= endY;j ++)
			{
				auto test = _grid->getNode(i,j);
				if (test == node ||
					!test->walkable ||
					!_grid->getNode(node->x,test->y)->walkable ||
					!_grid->getNode(test->x,node->y)->walkable)
				{
					continue;
				}

				float cost = _straightCost;
				if(!((node->x == test->x) || (node->y == test->y)))
				{
					cost = _diagCost;
				}

				float g = node->g + cost * test->costMultiplier;
				float h = _heuristic(test);
				float f = g + h;
				if(isOpen(test) || isClose(test))
				{
					if(test->f > f)
					{
						test->f = f;
						test->g = g;
						test->h = h;
						test->parent = node;
					}
				}
				else
				{
					test->f = f;
					test->g = g;
					test->h = h;
					test->parent = node;
					_open.pushBack(test);
				}
			}
		}
		_close.pushBack(node);
		if(_open.size() == 0)
		{
			CCLOG("no path found");
            _path = VectNode();
			return false;
		}
		sort(_open.begin(), _open.end(), AStar::sortOnF);
		node = *_open.begin();
		_open.erase(_open.begin());
	}

	buildPath();
	return true;
}

bool AStar::isOpen( CGridNode* node )
{
	int len = _open.size();
	for(int i = 0; i < len; i++)
	{
		if(_open.at(i) == node)
		{
			return true;
		}
	}
	return false;
}

bool AStar::isClose( CGridNode* node )
{
	int len = _close.size();
	for(int i = 0; i < len; i++)
	{
		if(_close.at(i) == node)
		{
			return true;
		}
	}
	return false;
}

bool AStar::sortOnF( CGridNode* a,CGridNode* b )
{
	return a->f < b->f;
}

void AStar::buildPath()
{
	_path = VectNode();
	auto node = _endNode;
	_path.pushBack(node);
	while (node != _startNode)
	{
		node = node->parent;
		_path.insert(0,node);
	}
}

void AStar::setHeuristicFunc( HeuristicType type )
{
	if (type == eManhattan){
		_heuristic = [&](CGridNode* node){
			return abs(node->x - _endNode->x) * _straightCost + abs(node->y + _endNode->y) * _straightCost;
		};
	}else if (type == eEuclidian){
		_heuristic = [&](CGridNode* node){
			float dx = node->x - _endNode->x;
			float dy = node->y - _endNode->y;
			return sqrt(dx * dx + dy * dy) * _straightCost;
		};
	}else if (type == eDiagonal){
		_heuristic = [&](CGridNode* node){
			float dx = abs(node->x - _endNode->x);
			float dy = abs(node->y - _endNode->y);
			float diag = min(dx, dy);
			float straight = dx + dy;
			return _diagCost * diag + _straightCost * (straight - 2 * diag);
		};
	}
}

VectNode AStar::getVisited()
{
	VectNode ret;
	ret.pushBack(_open);
	ret.pushBack(_close);
	return ret;
}
//////////////////////////////////////////////////////////////////////////
CMapRole::CMapRole()
:_node(nullptr)
,_speed(1)
,_lastPosition(Vec2::ZERO)
,_angel(0)
{
}

CMapRole::~CMapRole()
{
}

bool CMapRole::init(){
    return true;
}

CMapRole* CMapRole::create()
{
    CMapRole* pRet = new CMapRole();
    if( pRet && pRet->init() )
    {
        pRet->autorelease();
        return pRet;
    }
    CC_SAFE_DELETE(pRet);
    return NULL;
}

void CMapRole::setNode(Node* node)
{
    if (_node != node)
    {
        if (_node && _node->getParent())
        {
            _node->removeFromParent();
        }
        _node = node;
        addChild(node);
    }
}

void CMapRole::onUpdateDirection(){
    if (_lastPosition != getPosition()) {
        Vec2 oldPos = _lastPosition;
        _lastPosition = getPosition();
			
		Vec2 offsetPos = _lastPosition - oldPos;
		float offsetX = offsetPos.x;
		float offsetY = offsetPos.y;

        float angle = atan2(offsetY,offsetX) * 180 / 3.1415;
		if(angle<0) angle+= 360;

        //log("angle %f",angle);
		_angel = angle;

		if(angle> 337.5 || angle<= 22.5){
			_direction = Right;
		}else if(angle> 22.5 && angle<= 67.5){
			_direction = RightDown;
		}else if(angle> 67.5 && angle<= 112.5){
			_direction = Down;
		}else if(angle> 112.5 && angle<= 157.5){
			_direction = LeftDown;
		}else if(angle> 157.5 && angle<= 202.5){
			_direction = Left;
		}else if(angle> 202.5 && angle<= 247.5){
			_direction = LeftUp;
		}else if(angle> 247.5 && angle<= 292.5){
			_direction = LeftUp;
		}else if(angle> 292.5 && angle<= 337.5){
			_direction = Up;
		}
    }
}

CMapView::CMapView()
:_role(nullptr),
_autoSearchEnable(true),
_animatedMoveing(false),
_focusOnRole(true),
_moveTileOffset(Vec2::ZERO)
{
    setBounceable(false);
}

CMapView::~CMapView()
{
	_grid->release();
}

bool CMapView::initWithTMXFile( const std::string& tmxFile,const Size& size )
{
	if( initWithSize(size) )
	{
		_tileMap = cocos2d::experimental::TMXTiledMap::create(tmxFile);
        this->getContainer()->addChild(_tileMap);
        this->setContainerSize(_tileMap->getContentSize());
        
        auto mapSize = _tileMap->getMapSize();
		_grid = CMapGrid::create(mapSize.width,mapSize.height);
		_grid->retain();
    
        setFocusOnRole(true);
        
        return true;
	}
	return false;
}

void CMapView::setCollisionParam(const std::string& layerCollisionName,
                                 const std::string& tileCollisionName,
                                 const std::string& viewLayerName)
{
    _layerCollisionName = layerCollisionName;
    _tileCollisionName = tileCollisionName;
    _viewLayerName = viewLayerName;
    
    auto colliLayer = _tileMap->getLayer(_layerCollisionName);
    if (colliLayer)
    {
        auto colliLayerSize = colliLayer->getLayerSize();
        for (int i=0;i<colliLayerSize.width;i++)
        {
            for (int j=0;j<colliLayerSize.height;j++)
            {
                int gid = colliLayer->getTileGIDAt(Vec2(i,j));
                Value v = _tileMap->getPropertiesForGID(gid);
                if(v.isNull() == false && v.asValueMap()[_tileCollisionName].asBool()){
                    _grid->setWalkable(i,j,false);
                }
            }
        }
    }
}

CMapView* CMapView::create(const std::string& tmxFile,const Size& size)
{
	CMapView* pRet = new CMapView();
	if( pRet && pRet->initWithTMXFile(tmxFile,size) )
	{
		pRet->autorelease();
		return pRet;
	}
	CC_SAFE_DELETE(pRet);
	return NULL;
}

CWidgetTouchModel CMapView::onTouchBegan( Touch* pTouch )
{
    CScrollView::onTouchBegan(pTouch);
	return eWidgetTouchTransient;
}

void CMapView::onTouchMoved( Touch* pTouch, float fDuration )
{
    CScrollView::onTouchMoved(pTouch,fDuration);
}

void CMapView::perpareAnimatedMove()
{
    if( !_animatedMoveing )
    {
        schedule(schedule_selector(CMapView::performedAnimatedMoveing));
        _animatedMoveing = true;
    }
}

void CMapView::performedAnimatedMoveing(float dt)
{
    this->onMoveing();
	this->onMoveRole();

    this->executeMoveingHandler(this);
    if (_focusOnRole) {
        onFocusOnRole();
    }
	_role->onUpdateDirection();
}

void CMapView::stoppedAnimatedMove()
{
    if( _animatedMoveing )
    {
        unschedule(schedule_selector(CMapView::performedAnimatedMoveing));
        _animatedMoveing = false;
        
        this->onMoveing();
        this->executeMoveingHandler(this);
        this->executeMoveEndHandler(this);
    }
}

void CMapView::onTouchEnded( Touch* pTouch, float fDuration )
{
    CScrollView::onTouchEnded(pTouch,fDuration);
    
	Vec2 desPos = this->getContainer()->convertToNodeSpace(pTouch->getLocation());
	Vec2 tilePos = this->tilePosFromLocation(desPos);
	_grid->setEndNode(tilePos.x,tilePos.y);
    
    if (_autoSearchEnable && _role) {
        Vec2 tilePos = tilePosFromLocation(_role->getPosition());
        _grid->setStartNode(tilePos.x,tilePos.y);
        AStar::getInstance()->findPath(_grid);
		makeMovePaths(desPos);
			
        perpareAnimatedMove();
    }
}

void CMapView::makeMovePaths(const Vec2& targetPos)
{
	_movePaths.clear();
	auto viewLayer = _tileMap->getLayer(_viewLayerName);
	VectNode path = AStar::getInstance()->getPath();
	if (path.size() > 1)
	{
		for (int i = 1; i < path.size() - 1; i++)
		{
			Vec2 tmpPos = viewLayer->getPositionAt(path.at(i)->getPosition()) + _moveTileOffset;
			_movePaths.push_back(tmpPos);
		}
		_movePaths.push_back(targetPos);

	}else if(path.size() == 1){

		_movePaths.push_back(targetPos);
	}
}

void CMapView::onMoveRole()
{
	if (_role && _movePaths.size() > 0)
	{
		Vec2 tmpTarget = _movePaths.at(0);
		Vec2 currentPos = Vec2(_role->getPosition());
		Vec2 diff = tmpTarget - currentPos;
        
        if (diff.x != 0 && abs(diff.x) >= _role->getSpeed()) {
            diff.x > 0 ? currentPos.x += _role->getSpeed() : currentPos.x -= _role->getSpeed();
        }else{
            currentPos.x = tmpTarget.x;
        }
        if (diff.y != 0 && abs(diff.y) >= _role->getSpeed()) {
            diff.y > 0 ? currentPos.y += _role->getSpeed() : currentPos.y -= _role->getSpeed();
        }else{
            currentPos.y = tmpTarget.y;
        }
		_role->setPosition(currentPos);
		if (tmpTarget == currentPos)
		{
			_movePaths.erase(_movePaths.begin());

			if (_movePaths.size() == 0 ) 
				stoppedAnimatedMove();
		}
	}else{
		stoppedAnimatedMove();
	}
}

Vec2 CMapView::tilePosFromLocation( const Vec2& localPos )
{
	Vec2 pos = Vec2::ZERO;
	auto mapSize = _tileMap->getMapSize();
	auto tileSize = _tileMap->getTileSize();
	int posX = 0;
	int posY = 0;
    
	if (_tileMap->getMapOrientation() == TMXOrientationOrtho)
	{
		posX = (int)localPos.x / tileSize.width;
        auto tmpPos = localPos - _tileMap->getPosition();
        int tmp = mapSize.height * tileSize.height - tmpPos.y;
        posY = tmp / tileSize.height ;
        if (tmp % (int)tileSize.height == 0) {
            posY--;
        }

	}else if (_tileMap->getMapOrientation() == TMXOrientationIso){

		// Tilemap position must be subtracted, in case the tilemap position is not at 0,0 due to scrolling
		pos = localPos - _tileMap->getPosition();
		float halfMapWidth = mapSize.width * 0.5f;
		float mapHeight = mapSize.height;
		float tileWidth = tileSize.width;
		float tileHeight = tileSize.height;

		Vec2 tilePosDiv = Vec2(pos.x / tileWidth, pos.y / tileHeight);
		float inverseTileY = mapHeight - tilePosDiv.y;

		// Cast to int makes sure that result is in whole numbers, tile coordinates will be used as array indices
		posX = (int)(inverseTileY + tilePosDiv.x - halfMapWidth);
		posY = (int)(inverseTileY - tilePosDiv.x + halfMapWidth);
	}

	// make sure coordinates are within isomap bounds
	posX = MAX(0, posX);
	posX = MIN(mapSize.width - 1, posX);
	posY = MAX(0, posY);
	posY = MIN(mapSize.height - 1, posY);

	pos.set(posX, posY);
//	log("touch at (%.0f, %.0f) is at tileCoord (%i, %i)", localPos.x, localPos.y, (int)pos.x, (int)pos.y);
	return pos;
}

void CMapView::onFocusOnRole()
{
    if (_role == nullptr) {
        return;
    }
    
    Size mapNum = _tileMap->getMapSize();
    Size tileSize = _tileMap->getTileSize();
    Size mapSize = Size(mapNum.width * tileSize.width,mapNum.height * tileSize.height);
    Size visible = Director::getInstance()->getVisibleSize();
    Vec2 rolePos = _role->getPosition();
    
    float x = MAX(rolePos.x,visible.width/2);
    float y = MAX(rolePos.y,visible.height/2);
    
    x = MIN(x,mapSize.width - visible.width/2);
    y = MIN(y,mapSize.height - visible.height/2);
    
    Vec2 desPos = Vec2(x,y);
    Vec2 centerPos = Vec2(visible.width/2,visible.height/2);
    getContainer()->setPosition(centerPos-desPos);
}

void CMapView::setRole( Node* role ,const Vec2& pos,float speed)
{
	if (role)
	{
		if (_role == nullptr) {
			_role = CMapRole::create();
			_tileMap->addChild(_role);
		}
		_role->setNode(role);
		_role->setPosition(pos);
		_role->setSpeed(speed);

		if (_focusOnRole) {
			onFocusOnRole();
		}
	}else{
		CC_SAFE_RELEASE_NULL(_role);
	}
}

void CMapView::setFocusOnRole(bool b)
{
    _focusOnRole = b;
    setDragable(!b);

}

NS_CC_WIDGET_END