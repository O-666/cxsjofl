#include<stdio.h>//调用库函数
#include<stdlib.h>//定义复杂函数及内存分配函数
#include<conio.h>//控制台输入输出
#include<string.h>//字符串处理
typedef struct worker
{
	char workernumber[10];//职工工号
	char name[10];//职工姓名
	float post_salary;//岗位工资
	float pay_wages;//薪级工资
	float post_allowance;//职务津贴
	float performance_salary;//绩效工资
	float wages_payable;//应发工资
	float tax;//个人所得税
	float real_salary;//实发工资
}zggz;

int n=0;//职工人数，定义全局变量

int read(zggz zg[])//读取职工工资数据函数
{
	FILE *fp;//定义文件指针
	zggz z;
	if((fp=fopen("gx.dat","rb"))==NULL)//为只读打开一个gx.dat文件
	{
		printf("打开文件失败/n");
		exit (0);
	}

		while(!feof(fp))//从文件中读取数据信息
		{
			
			fscanf(fp,"%s\t",&z.workernumber);
			fscanf(fp,"%s\t",&z.name);
			fscanf(fp,"%f\t",&z.post_salary);
			fscanf(fp,"%f\t",&z.pay_wages);
			fscanf(fp,"%f\t",&z.post_allowance);
			fscanf(fp,"%f\t",&z.performance_salary);
			fscanf(fp,"%f\t",&z.wages_payable);
			fscanf(fp,"%f\t",&z.tax);
			fscanf(fp,"%f\t",&z.real_salary);
			zg[n]=z;
			n++;

		}
		fclose(fp);//关闭磁盘文件
		printf("读取完毕，共有%d人\n",n);
	    return n;
}

void write(zggz zg[])//保存职工工资数据函数
{
	FILE *fp;
	if((fp=fopen("gx.dat","wb"))==NULL)//为只写打开一个文件
			{
				printf("打开文件失败/n");
				exit (0);
			}
			if(n==0)
			{
				printf("职工人数为空");
			}
			//写入数据
			for(int i=0;i<n;i++)
				{
					fprintf(fp,"%s\t",zg[i].workernumber);
					fprintf(fp,"%s\t",zg[i].name);
					fprintf(fp,"%f\t",zg[i].post_salary);
					fprintf(fp,"%f\t",zg[i].pay_wages);
					fprintf(fp,"%f\t",zg[i].post_allowance);
					fprintf(fp,"%f\t",zg[i].performance_salary);
					fprintf(fp,"%f\t",zg[i].wages_payable);
					fprintf(fp,"%f\t",zg[i].tax);
					fprintf(fp,"%f\t",zg[i].real_salary);
				}
	fclose(fp);
}

void find(zggz zg[])//查询职工数据函数
{
	int i;//记录员工存在的位置
	int flag=0;//标记员工有没有存在
	int j;//记录员工位置（查询的工号存在相同时）
	char gonghao[10];
	printf("请输入要查询员工的工号：");
	scanf("%s",&gonghao);
	//遍历结构体数组，查找有无该工号的员工，若有flag=1,反之flag=0
	for(i=0;i<n;i++)
	{
		if(strcmp(zg[i].workernumber,gonghao)==0)
		{
			flag=1;
			break;
		}
		
	}
	//如果存在该工号则输出该员工的信息
	if(flag)
	{
		printf("工号\t姓名\t岗位工资\t薪级工资\t职务津贴\t绩效工资\t应发工资\t个人所得税\t实发工资\n");
		printf("%s\t",zg[i].workernumber);
		printf("%s\t",zg[i].name);
		printf("%f\t",zg[i].post_salary);
		printf("%f\t",zg[i].pay_wages);
		printf("%f\t",zg[i].post_allowance);
		printf("%f\t",zg[i].performance_salary);
		printf("%f\t",zg[i].wages_payable);
		printf("%f\t",zg[i].tax);
		printf("%f\t",zg[i].real_salary);
		//zggz数组中可能有多个工号一样的员工，需要继续查找，用j来标记员工的位置
		///第二次寻找的起始位置应该从i+1的位置开始因为之前的已经找过了
		for(j=i+1;j<n;j++)
		{
			//字符串与字符串不能之间相等，所以使用strcmp进行比较
			if(strcmp(zg[j].workernumber,gonghao)==0)
			{
				printf("%s\t",zg[j].workernumber);
		        printf("%s\t",zg[j].name);
	        	printf("%f\t",zg[j].post_salary);
		        printf("%f\t",zg[j].pay_wages);
		        printf("%f\t",zg[j].post_allowance);
		        printf("%f\t",zg[j].performance_salary);
		        printf("%f\t",zg[j].wages_payable);
	          	printf("%f\t",zg[j].tax);
	         	printf("%f\t",zg[j].real_salary);
			}
		}

	}
	else
	{
		printf("没有找到该工号的员工！\n");
	}
	printf("\n");
	system("pause");
}

float grsds(zggz zg[])//计算个人所得税函数
{
	float tax=0;//定义一个单精度浮点型数据tax
	for(int i=0;i<n;i++)
	{
		if(zg[i].wages_payable<=0)
		{
			zg[i].tax=0;
		}
		if(zg[i].wages_payable<=500)
		{
			zg[i].tax=float(zg[i].wages_payable*0.05);tax=zg[i].tax;
		}
	    if(zg[i].wages_payable>500 && zg[i].wages_payable<=2000)
		{
			zg[i].tax=float(zg[i].wages_payable*0.1);tax=zg[i].tax;
		}
	    if(zg[i].wages_payable>2000 && zg[i].wages_payable<=5000)
		{
			zg[i].tax=float(zg[i].wages_payable*0.15);tax=zg[i].tax;
		}
		if(zg[i].wages_payable>5000 && zg[i].wages_payable<=20000)
		{
			zg[i].tax=float(zg[i].wages_payable*0.2);tax=zg[i].tax;
		}
		if(zg[i].wages_payable>20000 && zg[i].wages_payable<=40000)
		{
			zg[i].tax=float(zg[i].wages_payable*0.25);tax=zg[i].tax;
		}
		if(zg[i].wages_payable>40000 && zg[i].wages_payable<=60000)
		{
			zg[i].tax=float(zg[i].wages_payable*0.3);tax=zg[i].tax;
		}
		if(zg[i].wages_payable>60000 && zg[i].wages_payable<=80000)
		{
			zg[i].tax=float(zg[i].wages_payable*0.35);tax=zg[i].tax;
		}
		if(zg[i].wages_payable>80000 && zg[i].wages_payable<=100000)
		{
			zg[i].tax=float(zg[i].wages_payable*0.4);tax=zg[i].tax;
		}
		if(zg[i].wages_payable>100000)
		{
			zg[i].tax=float(zg[i].wages_payable*0.45);tax=zg[i].tax;
		}
	}
	return tax;
}

void list(zggz zg[])//浏览职工工资数据函数
{
	int i=0;
	printf("输出所有职工记录：\n");
	printf("工号\t姓名\t岗位工资\t薪级工资\t职务津贴\t绩效工资\t应发工资\t个人所得税\t实发工资\n");
	for(i=0;i<n;i++)
	{
		//grsds(zg);
		printf("\n");
		printf("%s\t",zg[i].workernumber);
		printf("%s\t",zg[i].name);
	   	printf("%f\t",zg[i].post_salary);
		printf("%f\t",zg[i].pay_wages);
		printf("%f\t",zg[i].post_allowance);
	    printf("%f\t",zg[i].performance_salary);
		printf("%f\t",zg[i].wages_payable);
	    printf("%f\t",zg[i].tax);
	    printf("%f\n",zg[i].real_salary);

	}
}

void modify(zggz zg[])//修改职工工资数据函数
{
	int i=0;
	int x=0;
	char gonghao[10];
	printf("请输入你要修改的职工工号：");
    scanf("%s",gonghao);
//	find(zg);
    for(i=0;i<n;i++)
	{
		if(!strcmp(gonghao,zg[i].workernumber))
		{
			printf("请输入修改后职工的工号：");
      	    scanf("%s",&zg[i].workernumber);
        	printf("请输入修改后职工的姓名：");
        	scanf("%s",&zg[i].name);
	        printf("请输入修改后职工的岗位工资：");
    	    scanf("%f",&zg[i].post_salary);
        	printf("请输入修改后职工的薪级工资：");
        	scanf("%f",&zg[i].pay_wages);
        	printf("请输入修改后职工的职务津贴：");
        	scanf("%f",&zg[i].post_allowance);
			printf("请输入修改后职工的绩效工资：");
        	scanf("%f",&zg[i].performance_salary);
        	zg[i].wages_payable=zg[i].post_salary +zg[i].pay_wages+zg[i].post_allowance +zg[i].performance_salary;
			grsds(zg);
			zg[i].real_salary =zg[i].wages_payable -zg[i].tax;
        	x++;
			printf("-------------修改成功------------\n");
       }
		if(x==0)
		{
			printf("未找到要修改的编号\n");
       }
	}
	   write(zg);

}

int add(zggz zg[],int n)//添加职工工资数据函数
{
	int i;
    int x=0;
    char gonghao[10];
    printf("请输入你要添加的职工的编号：");
    scanf("%s",gonghao);
	for(i=0;i<n;i++)
		if(strcmp(gonghao,zg[i].workernumber)==0)
              {
                     x=i;
                     for(i=n;i>x+1;i--)
                     {
						 zg[i].post_salary=zg[i-1].post_salary;
                         zg[i].pay_wages=zg[i-1].pay_wages;
                         zg[i].post_allowance=zg[i-1].post_allowance;
                         zg[i].performance_salary=zg[i-1].performance_salary;
                         zg[i].wages_payable=zg[i-1].wages_payable;
                         zg[i].tax=zg[i-1].tax;
					     zg[i].real_salary=zg[i-1].real_salary;
                         strcpy(zg[i].name,zg[i-1].name);
                         strcpy(zg[i].workernumber,zg[i-1].workernumber);
                     }
              }
              x++;
			  printf("\n");
			  printf("请输入你添加的职工工号：\n");
		      scanf("%s",&zg[x].workernumber);
			  printf("请输入你添加的职工姓名：\n");
	       	  scanf("%s",&zg[x].name);
			  printf("请输入你添加的职工的岗位工资：\n");
		   	  scanf("%f",&zg[x].post_salary);
			  printf("请输入你添加的职工的薪级工资：\n");
		   	  scanf("%f",&zg[x].pay_wages);
			  printf("请输入你添加的职工的职务津贴：\n");
		   	  scanf("%f",&zg[x].post_allowance);
			  printf("请输入添加后职工的绩效工资：\n");
        	  scanf("%f",&zg[x].performance_salary);
		   	  zg[x].wages_payable=zg[x].post_salary +zg[x].pay_wages+zg[x].post_allowance +zg[x].performance_salary;
		   	  grsds(zg);
		   	  zg[x].real_salary =zg[x].wages_payable -zg[x].tax;
			  printf("添加职工信息成功！\n");
	
	write(zg);
	return n+1;
}

int del(zggz zg[],int n)//删除职工工资数据函数
{
	   int i=0;
       int j=0;//删除的职工记录数
       char gonghao[10];
       printf("请输入你要删除的职工工号");
       scanf("%s",gonghao);
       for(i=0;i<n;i++)
       if(!strcmp(gonghao,zg[i].workernumber))
       {
              while(i<n)
              {
                     strcpy(zg[i].workernumber,zg[i+1].workernumber);
					 strcpy(zg[i].name,zg[i+1].name);
                     zg[i].post_salary=zg[i+1].post_salary;
                     zg[i].pay_wages=zg[i+1].pay_wages;
                     zg[i].post_allowance=zg[i+1].post_allowance;
                     zg[i].performance_salary=zg[i+1].performance_salary;
                     zg[i].wages_payable=zg[i+1].wages_payable;
                     zg[i].tax=zg[i+1].tax;
					 zg[i].real_salary=zg[i+1].real_salary;
                     i++;
					 printf("删除成功！\n");
              }
              j++;
       }
       if(j==0)
       {
              printf("输入的编号或姓名不存在，请重新输入：\n");
       }
	   write(zg);
       return n-j;
}

int main()
{  
	zggz z[100];
	int choose=0;//选择按钮
	read(z);//调用读入函数
	//do_while循环实现循环此功能
	do
	{
		printf("\n");
		system("pause");
		system("cls");//清屏
		printf("### 欢迎使用广西民族大学软件与信息安全学院职工工资管理系统 ###\n");
	    printf("\n");
        printf("请选择<1-7>\n");
        printf("==============================================================\n");
        printf("|          1.查询职工工资记录                                 |\n");
        printf("|          2.修改职工工资记录                                 |\n");
	    printf("|          3.添加职工工资记录                                 |\n");
	    printf("|          4.删除职工工资记录                                 |\n");
	    printf("|          5.保存数据到文件                                   |\n");
	    printf("|          6.浏览职工记录                                     |\n");
	    printf("|          7.退出系统                                         |\n");
        printf("==============================================================\n");
	    printf("\n");
        printf("你的选择是：\n");
		scanf("%d",&choose);
		switch(choose)
		{
		case 1:
			find(z);
			break;
		case 2:
			modify(z);
			break;
		case 3:
			add(z,n);
			break;
		case 4:
			del(z,n);
			break;
		case 5:
			write(z);
			break;
		case 6:
			list(z);
			break;
		case 7:
			puts("\n谢谢使用/n");
			return 0;
		default:
			printf("\n输入错误，请重新输入选择：");
			scanf("%d",&choose);
			break;
		}

	}
	while(choose!=-1);
	write(z);
	return 0;

}