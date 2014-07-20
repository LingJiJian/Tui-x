Tui-x
=====

![](picture/pic1.jpg)
![](picture/pic2.jpg)

This Tui-x cocos2dx 3.x version,more light,more sample,more flexible

简介：

Tui是一个创建cocos2d-x UI界面的解决方案，而builder用的则是FlashCS，这个项目所用的版本是cocos2d-x 3.2正式版，
而所用的组件库为CocosWidget3.2，如果是2.2.x版本的项目请移步到https://github.com/LingJiJian/tui/tree/Tui-x

特性:

0.持续更新，伴随官方的最新引擎发布。                            
1.Tui-x3.x 所采用的是RapidXml解析库，效率是tinyxml的50倍。		    
2.可视化编辑文本描边和阴影和对齐。							            
3.可视化编辑ListView，TableView，GridView等复合控件。     
4.支持添加命名空间，避免资源命名冲突或过长。				  							
5.支持多fla编辑场景。															            			
6*.影片剪辑控件MovieView，支持自定义事件，用于制作长时间动画。动画编辑工具后期发布。	
7.包含旋转菜单控件。		                                       
8.兼容lua和cpp。                                      
9.资源管理全部交由开发者控制，自由，控件资源可跨场景重用。						

说明:

注：本项目中的HelloTuiLua/Cpp 是演示工程，需要自己放置引擎代码到相应的位置。					
Cpp具体操作：下载好的cocos2dx3.0的引擎，然后直接把这个引擎改名成cocos2d，复制到Tui-x/HelloTuiCpp下，			
Lua具体操作：下载好的cocos2dx3.0的引擎，然后直接把这个引擎改名成cocos2d-x，复制到Tui-x/HelloTuiLua/frameworks下。
Cpp版，打开cocos/ui/UILayoutDefine.h , 注释掉 54行 //const Margin MarginZero = Margin(); 
Lua版，不用注释

接下来双击sln就可以开始编译了！

（为什么要这么做？这是因为我们不需要用到官方的UI库，我们只用CocosWidget的组件就能完全替代它，如果你不注释
这一行，那么vs在编译的时候，会发现Margin未定义，如果你不想注释也可以，但你必须要引入官方的UI库，那你就
有两个组件库了。。何必呢- -）

教程：
注意：Tui-x 3.0和Tui-x 2.2.x接口有少量区别！具体请看HelloTui							
教程：http://blog.csdn.net/ab342854406/article/details/37706111
