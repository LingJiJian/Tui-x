//遍历库 切割九宫格
/*
	之前的img9的九宫图有人说看起来不直观, 现在只要对舞台上的位图进行 "转换元件" 操作,并勾选开启九宫格，转换成影片剪辑后，再运行该脚本就可以了。刚刚转化完的元件就是九宫图，拉伸看看？
*/
var doc = fl.getDocumentDOM();
var lib = doc.library;
var items = lib.getSelectedItems();
var count = 0;
for each (var item in items)
{
	if (item.scalingGrid)
	{
		lib.editItem( item.name );
		doc.selectAll();
		try
		{
			doc.breakApart();
		}
		catch(err)
		{
		}

		var rect = item.scalingGridRect;
		doc.setSelectionRect( { left:-1000, top:-1000, right:rect.left, bottom:rect.top } );
		doc.group();
		doc.setSelectionRect( { left:rect.left, top:-1000, right:rect.right, bottom:rect.top } );
		doc.group();
		doc.setSelectionRect( { left:rect.right, top:-1000, right:1000, bottom:rect.top } );
		doc.group();
		doc.setSelectionRect( { left:-1000, top:rect.top, right:rect.left, bottom:rect.bottom } );
		doc.group();
		doc.setSelectionRect( { left:rect.left, top:rect.top, right:rect.right, bottom:rect.bottom } );
		doc.group();
		doc.setSelectionRect( { left:rect.right, top:rect.top, right:1000, bottom:rect.bottom } );
		doc.group();
		doc.setSelectionRect( { left:-1000, top:rect.bottom, right:rect.left, bottom:1000 } );
		doc.group();
		doc.setSelectionRect( { left:rect.left, top:rect.bottom, right:rect.right, bottom:1000 } );
		doc.group();
		doc.setSelectionRect( { left:rect.right, top:rect.bottom, right:1000, bottom:1000 } );
		doc.group();
		count ++;
	}
}

fl.outputPanel.trace( "转化完成, 成功量: "+count);