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
#ifndef __CCWIDGET_MAPVIEW_H__
#define __CCWIDGET_MAPVIEW_H__

#include "2d/CCFastTMXLayer.h"
#include "2d/CCFastTMXTiledMap.h"
#include "ScrollView.h"

NS_CC_WIDGET_BEGIN

using namespace std;
class CMapView;
class CMapGrid;
class CMapRole;
class CGridNode;

typedef Vector<CGridNode*> VectNode ;

class CGridNode : public Ref
{
public:
	static CGridNode* create(int x,int y);
	bool init(int x,int y);
	int x;
	int y;
	float f;
	float g;
	float h;
	bool walkable;
	CGridNode *parent;
	float costMultiplier;
    Vec2 getPosition(){ return Vec2(x,y); };
};

class CMapGrid : public Ref
{
public:
	static CMapGrid* create(int numCols,int numRows);
	bool init(int numCols,int numRows);
	CGridNode *getNode(int x,int y) { return _nodes[x].at(y); };
	void setStartNode(int x,int y);
	void setEndNode(int x,int y);
	void setWalkable(int x,int y,bool b) { _nodes[x].at(y)->walkable = b; };
	CGridNode* getStartNode(){ return _startNode;};
	CGridNode* getEndNode(){ return _endNode;};
	int getNumCols(){ return _numCols;};
	int getNumRows(){ return _numRows;};
	
private:
	CGridNode* _startNode;
	CGridNode* _endNode;
	int _numCols;
	int _numRows;
	vector<VectNode> _nodes;
};

enum HeuristicType{
	eManhattan,
	eEuclidian,
	eDiagonal,
};

class AStar : public Ref
{
public:
	AStar():
		_straightCost(1),
		_diagCost(sqrt(2)){};
	virtual bool init();
	static AStar *getInstance();

	bool findPath(CMapGrid *grid);
	bool search();
	void buildPath();
	VectNode getPath(){return _path;};
	void setHeuristicFunc(HeuristicType type);
	VectNode getVisited();
protected:
	bool isOpen(CGridNode* node);
	bool isClose(CGridNode* node);
	static bool sortOnF(CGridNode* a,CGridNode* b);
private:
	VectNode _open;
	VectNode _close;
	CMapGrid* _grid;
	CGridNode* _startNode;
	CGridNode* _endNode;
	VectNode _path;
	float _straightCost;
	float _diagCost;
	function<float(CGridNode*)> _heuristic;
};

//////////////////////////////////////////////////////////////////////////
enum eRoleDirection {
    LeftUp,
    Up,
    RightUp,
    Right,
    RightDown,
    Down,
    LeftDown,
    Left
};

class CMapRole : public CWidget,public Node
{
public:
    CMapRole();
    ~CMapRole();
    bool init();
    static CMapRole* create();
    void setNode(Node* node);
    bool isMoveing(){ return _isMoveing; };
    CC_SYNTHESIZE(float, _speed, Speed);
    CC_SYNTHESIZE(eRoleDirection,_direction,Direction);
	CC_SYNTHESIZE(float,_angel,Angel);
protected:
    void onUpdateDirection();
protected:
    Vec2 _lastPosition;
    Node* _node;
    bool _isMoveing;
    friend class CMapView;
    
};

class CMapView : public CScrollView,public CMoveProtocol
{
public:
	CMapView();
	~CMapView();
	static CMapView* create(const std::string& tmxFile ,const Size& size);
	bool initWithTMXFile(const std::string& tmxFile,const Size& size);
	CC_SYNTHESIZE_READONLY(CMapGrid*,_grid,Grid);
	CC_SYNTHESIZE_READONLY(cocos2d::experimental::TMXTiledMap*,_tileMap,TileMap);
	CC_SYNTHESIZE(bool,_autoSearchEnable,AutoSearchEnabled);
    
    void setFocusOnRole(bool b);
    void setMoveTileOffset(const Vec2& pos);
    void setCollisionParam(const std::string& layerCollisionName,
                           const std::string& tileCollisionName,
                           const std::string& viewLayerName);
    
	void setRole(Node* role,const Vec2& pos,float speed=0.1f);
    CMapRole* getRole(){ return _role;};
    
	Vec2 tilePosFromLocation(const Vec2& localPos);

	virtual CWidgetTouchModel onTouchBegan(Touch* pTouch);
	virtual void onTouchMoved(Touch* pTouch, float fDuration);
	virtual void onTouchEnded(Touch* pTouch, float fDuration);

protected:
    void onFocusOnRole();
    void perpareAnimatedMove();
    void performedAnimatedMoveing(float dt);
    void stoppedAnimatedMove();
    void onMoveing(){};
	void onMoveRole();
	void makeMovePaths(const Vec2& targetPos);
protected:
    CMapRole* _role;
    bool _animatedMoveing;
    bool _focusOnRole;
    Vec2 _moveTileOffset;
    string _layerCollisionName;
    string _tileCollisionName;
    string _viewLayerName;
	vector<Vec2> _movePaths;
};

NS_CC_WIDGET_END

#endif //__CCWIDGET_MAPVIEW_H__ 