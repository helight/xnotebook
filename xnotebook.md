### 一、软件介绍： ###
Zhwen-Xnotebook是一款用gtk＋开发的文本资料管理软件，它主要用于个人文本资料的分类管理。并且具有RSS订阅功能。<br>

xnotebook也开始向广大网友征求logo啦。。。。希望大家多多支持！<br>
<br>
<img src='http://zhwen.org/proj/xnotebook.png' />
<h3>二、安装使用：</h3>
项目源码下载：<br>
项目管理地址：<a href='http://code.google.com/p/xnotebook/'>http://code.google.com/p/xnotebook/</a><br>
svn checkout <a href='http://xnotebook.googlecode.com/svn/trunk/'>http://xnotebook.googlecode.com/svn/trunk/</a> xnotebook <br>
在这上面使用svn下载源码即可进行编译安装。<br>
或者在下面的地址下载源码压缩包：<br>
<a href='http://code.google.com/p/xnotebook/downloads/list'>http://code.google.com/p/xnotebook/downloads/list</a><br>
下载后解压到某处即可进行安装。<br>
需要安装的库和工具：<br>
make, automake，libglib2.0-dev，libgtk2.0-dev<br>
在项目文件根目录下执行一下命令即可：<br>
xnotebook$ ./autogen.sh<br>
xnotebook$ make<br>
xnotebook$ sudo make install<br>
xnotebook$ xnotebook<br>
这样既可以使用该软件了。<br><br>

<h3>三、具体功能：</h3>
1.新建分类：点击工具栏上“New Folder”则会弹出一个对话框，输入要建立分类的名称即可。保证新建名称符合Linux系统文件名命名规则。也可以使用右键菜单来操作。<br>
2.新建分类下面文件：点击工具栏上“New Note”则会弹出一个对话框，输入要建立文件的名称即可。也可以使用右键菜单来操作。<br>
3.编辑文件：选择具体文件后，即可看到文件内容显示到了文本浏览区。事实上这时的文本区是只可浏览不可编辑的，点击工具栏上“Edit”后文本区才进入可编辑模式。这时便可以编辑文件。编辑后点击工具栏上“Save”后即可保存。<br>
4.其它还有删除具体分类及其内容，删除具体文件和退出等功能。也可以使用右键菜单来操作。<br>
5.重命名具体分类和具体文件。也可以使用右键菜单来操作。<br>
6.日历查看功能，“tools”菜单项中集成了一个简单的日历，一方便日期查询。<br>
7.支持快捷键，具体请看菜单。<br><br>
<h3>四、进一步要实现功能：</h3>
1.RSS订阅功能。<br>
2.搜索功能。<br>
<br><br>

<h3>五、关于作者：</h3>
该软件作者：（Zhwen Xu）Helight.xu@gmail.com<br>
个人站点：<a href='http://zhwen.org'>http://zhwen.org</a><br>
如果在使用中发现什么bug请发邮件通知我，我会尽快改进。<br>