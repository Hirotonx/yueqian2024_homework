#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <strings.h>

/*
	linux一切都是文件--》不是吹牛
	操作液晶屏
	     液晶屏：7英寸
		 分辨率：800*480
		 液晶屏显示图像：都是通过一个个像素点显示
		                 液晶屏每个像素点占4个字节，4个字节分别表示A R G B的颜色值
						 RGB是计算机用来表示各种颜色的一种编码格式
						 A --》透明度
						 R --》红色
						 G --》绿色
						 B --》蓝色
		我想把液晶屏刷成红色
*/
int main(int argc,char **argv)
{
	int lcdfd;
	int i;
	//定义变量表示红颜色
	//         A R G B
	int red=0x00ff0000;
	
	//第一步；打开液晶屏的驱动
	lcdfd=open("/dev/fb0",O_RDWR);
	if(lcdfd==-1)
	{
		printf("打开液晶屏失败了!\n");
		return -1;
	}
	
	//第二步：write往液晶屏中写入颜色值即可
	//先写入一个像素点的颜色值
	int color[3] = {0x00005FA4, 0xFFFFFFFF, 0x00FA3C32};
	for(i=0; i<800*480; i++)
        if (i % 800 <= 240)
            write(lcdfd, &color[0], 4);
        else if (i % 800 <= 504 && i % 800 > 240)
            write(lcdfd, &color[1], 4);
        else if (i % 800 > 264)
            write(lcdfd, &color[2], 4);

    //关闭
	close(lcdfd);
	return 0;
	
}
