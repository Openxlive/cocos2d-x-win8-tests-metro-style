coco2d-x Windows8 Metro风格Tests Show是Nowpaper基于cocos2d-x.org中发布的cocos2dx-win8-5af127f版本修改调整发布。
主要调整修改了主菜单项界面，使之更为接近Metro风格，参考微软发布的Metro Ui设计指南和其他设计资源，注意：该版本并未完全按照Metro Ui设计规范进行设计。


代码文件修改说明：
AppDelegate.cpp : 从默认的尺寸调整了到800x480的尺寸，因原始像素太小，在Win8上看起来不适。
CCMetroTpyes.h : 原版没有，个人新增，增加了微软Metro设计规范中的颜色定义
CMenuItemMetro类（CMenuItemMetro.h CMenuItemMetro.cpp）：原版没有，个人新增，符合个人需求的Metro MenuItem。
controller.h : 增加了ccTouchesEnded重载
controller.cpp : 在初始化里增加按钮重新布局，增加了一个plist的图标文件用来辅助显示图标，修改了TouchMove逻辑简化处理并使之横向动画，增加了菜单屏幕的滑动动画处理(手指快速滑动屏幕)。
close.png : 依据整体风格做了图片修改
close-HD.png : 依据整体风格做了图片修改

在Art里有全套的原始设计文件，你可以依据需要自行修改。

注意：
点击标题才能进入对应的Test，只是点击颜色方块是不行的
当前的cocos2d-x Win8版本可能底层存在一些问题，渲染效率不高，可能会有卡顿的现象


微博：http://www.weibo.com/nowpaper
博客：http://www.cnblogs.com/nowpaper
QQ：2232199564