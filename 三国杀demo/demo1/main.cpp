#include <graphics.h>		// 引用图形库头文件
#include <conio.h>
#include <easyx.h>
#include <iostream>
#pragma comment( lib, "MSIMG32.LIB")

void transparentimage(int x, int y, IMAGE img) {
	IMAGE img1;
	DWORD* d1;
	img1 = img;
	d1 = GetImageBuffer(&img1);
	float h, s, l;
	for (int i = 0; i < img1.getheight() * img1.getwidth(); i++) {
		RGBtoHSL(BGR(d1[i]), &h, &s, &l);
		if (l < 0.03) {
			d1[i] = BGR(WHITE);
		}
		if (d1[i] != BGR(WHITE)) {
			d1[i] = 0;
		}
	}
	putimage(x, y, &img1, SRCAND);
	putimage(x, y, &img, SRCPAINT);
}

void Initgraph()
{
	IMAGE img;
	loadimage(&img, "background.jpg", 1600, 800);
	putimage(0, 0, &img);

	IMAGE img2;
	loadimage(&img2, "button1.png", 150, 50);
	transparentimage(1450, 0, img2);


	transparentimage(600, 550, img2);
	transparentimage(800, 550, img2);

	setfillcolor(RGB(247, 242, 214));
	fillrectangle(0, 600, 1600, 800);

	settextstyle(36, 0, _T("黑体"));	// 设置字体样式
	settextcolor(BLACK);		// 设置文本颜色
	setbkmode(TRANSPARENT);		// 设置背景模式为透明
	outtextxy(1450 + (150 - textwidth(_T("菜单"))) / 2, (50 - textheight(_T("菜单"))) / 2, _T("菜单"));
	outtextxy(600 + (150 - textwidth(_T("确定"))) / 2, 550 + (50 - textheight(_T("确定"))) / 2, _T("确定"));
	outtextxy(800 + (150 - textwidth(_T("取消"))) / 2, 550 + (50 - textheight(_T("取消"))) / 2, _T("取消"));

}

int main()
{
	initgraph(1600,800, EX_SHOWCONSOLE);	// 创建绘图窗口，大小为 640x480 像素
	
	Initgraph();
	

	getchar();

	return 0;
}
