#include<stdio.h>//调用库函数
#include<stdlib.h>//定义复杂函数及内存分配函数
#include<conio.h>//控制台输入输出
#include<string.h>//字符串处理
#include<windows.h>//调用fwrite等函数
#define NUM 50//宏定义
struct worker
{
	char workernumber;//职工工号
	char name[20];//职工姓名
	float post_salary;//岗位工资
	float pay_wages;//薪级工资
	float post_allowance;//职务津贴
	float performance_salary;//绩效工资
	float wages_payable;//应发工资
	float personal_income_tax;//个人所得税
	float real_salary;//实发工资
};
struct worker zggz[NUM];
	struct worker z;
struct worker *p=zggz;

int read(struct worker zggz[])//读取职工工资数据函数
{
    int n;//职工人数
	//scanf("%d",&n);
	FILE *fp;//定义文件指针
	struct worker z;
	if((fp=fopen("gx.dat","r"))==NULL)//为输入打开一个gx.dat文件
	{
		printf("打开文件失败/n");
		exit (0);
	}

	if(NULL!=fp)//如果文件打开成功
	{
			fp=fopen("gx.dat","a+");
			fseek(fp,0,SEEK_END);//文件指针到文件尾
		while(!feof(fp))//从文件中读取数据信息
		{
			
			fscanf(fp,"%c",&z.workernumber);
			fscanf(fp,"%c",&z.name);
			fscanf(fp,"%f",&z.post_salary);
			fscanf(fp,"%f",&z.pay_wages);
			fscanf(fp,"%f",&z.post_allowance);
			fscanf(fp,"%f",&z.performance_salary);
			fscanf(fp,"%f",&z.wages_payable);
			fscanf(fp,"%f",&z.personal_income_tax);
			fscanf(fp,"%f",&z.real_salary);
			zggz[n]=z;
			n++;

		}

			fclose(fp);//关闭磁盘文件
	}
	return n;
}

void write(struct worker zggz[],int n)//保存职工工资数据函数
{
	FILE *fp;
	if((fp=fopen("gz.dat","w"))==NULL)//为写打开一个文件
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
					fprintf(fp,"%c",zggz[i].workernumber);
					fprintf(fp,"%c",zggz[i].name);
					fprintf(fp,"%f",zggz[i].post_salary);
					fprintf(fp,"%f",zggz[i].pay_wages);
					fprintf(fp,"%f",zggz[i].post_allowance);
					fprintf(fp,"%f",zggz[i].performance_salary);
					fprintf(fp,"%f",zggz[i].wages_payable);
					fprintf(fp,"%f",zggz[i].personal_income_tax);
					fprintf(fp,"%f",zggz[i].real_salary);
				}
	fclose(fp);
}
void find(struct worker zggz[],int n)//查询职工数据函数
{
	int i;//记录员工存在的位置
	int j;//记录员工位置（查询的工号存在相同时）
	int flag=0;//标记员工有没有存在
	char gonghao[20];
	printf("请输入要查询员工的工号：");
	scanf("%c",&gonghao);
	//遍历结构体数组，查找有无该工号的员工，若有flag=1,反之flag=0
	for(i=0;i<n;i++)
	{
		if(strcmp(zggz[i].workernumber,gonghao)==0)
		{
			flag=1;
			break;
		}
		
	}
	//如果存在该工号则输出该员工的信息
	if(flag)
	{
		printf("工号\t姓名\t岗位工资\t薪级工资\t职务津贴\t绩效工资\t应发工资\t个人所得税\t实发工资\n");
		printf("%c\t",zggz[i].workernumber);
		printf("%c\t",zggz[i].name);
		printf("%f\t",zggz[i].post_salary);
		printf("%f\t",zggz[i].pay_wages);
		printf("%f\t",zggz[i].post_allowance);
		printf("%f\t",zggz[i].performance_salary);
		printf("%f\t",zggz[i].wages_payable);
		printf("%f\t",zggz[i].personal_income_tax);
		printf("%f\t",zggz[i].real_salary);
		//zggz数组中可能有多个工号一样的员工，需要继续查找，用j来标记员工的位置
		///第二次寻找的起始位置应该从i+1的位置开始因为之前的已经找过了
		for(j=i+1;j<n;j++)
		{
			//字符串与字符串不能之间相等，所以使用strcmp进行比较
			if(strcmp(zggz[j].workernumber,gonghao)==0)
			{
				printf("%c\t",zggz[j].workernumber);
		        printf("%c\t",zggz[j].name);
	        	printf("%f\t",zggz[j].post_salary);
		        printf("%f\t",zggz[j].pay_wages);
		        printf("%f\t",zggz[j].post_allowance);
		        printf("%f\t",zggz[j].performance_salary);
		        printf("%f\t",zggz[j].wages_payable);
	          	printf("%f\t",zggz[j].personal_income_tax);
	         	printf("%f\t",zggz[j].real_salary);
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
void list(struct worker zggz[],int n)//浏览职工工资数据函数
{
	printf("输出所有职工记录：");
	for(int i=0;i<=n;i++)
	{
		printf("**********\n");
		printf("%c\n",zggz[i].name);
	   	printf("%f\n",zggz[i].post_salary);
		printf("%f\n",zggz[i].pay_wages);
		printf("%f\n",zggz[i].post_allowance);
	    printf("%f\n",zggz[i].performance_salary);
		printf("%f\n",zggz[i].wages_payable);
	    printf("%f\n",zggz[i].personal_income_tax);
	    printf("%f\n",zggz[i].real_salary);
		printf("**********\n");

	}
}
void modify(struct worker zggz[],int n)//修改职工工资数据函数
{
	int flag=0;//标记是否被修改
	char gonghao[20];
	printf("请输入要修改的职工的工号：");
	scanf("%c",&gonghao);
	for(int i=0;i<n;i++)
	{
		if(strcmp(zggz[i].workernumber,gonghao)==0)
		{
			if(zggz[i].workernumber==gonghao)
			{
				printf("修改前后的信息不能一样！\n");
				break;
			}
			zggz[i].workernumber=gonghao;
			flag=1;
		}
	}
	if(flag==0)
	{
		printf("修改信息失败\n");
	}
	else
	{
		printf("修改信息成功\n");
		writeFile(zggz,n);
		system("pause");
		break;
	}
}
void grsds(struct worker zggz[], int n)//计算个人所得税函数
{
	FILE *fp;
	fp=fopen("gz.dat","w");
	if(n==0)
	{
		printf("\n员工信息表中没有信息！/n");
		return;
	}
	else{
		puts("");
	}
}
void add(struct worker zggz[])//添加职工工资数据函数
{
	FILE *fp;
	int n,i,j;
	if((fp=fopen("emp.txt","ab+"))==NULL)
	{
		printf("不能打开emp文件\n");
		exit(0);
	} 
	printf("要添加的职工工资人数:");
	scanf("%d",&n); 
	for(i=0;i<n;i++)
	{
		printf("工号\t姓名\t岗位工资\t薪级工资\t职务津贴\t绩效工资\t应发工资\t个人所得税\t实发工资\n");
		scanf("%c\t",&zggz[i].workernumber);
		scanf("%c\t",&zggz[i].name);
		scanf("%f\t",&zggz[i].post_salary);
		scanf("%f\t",&zggz[i].pay_wages);
		scanf("%f\t",&zggz[i].post_allowance);
		scanf("%f\t",&zggz[i].performance_salary);
		scanf("%f\t",&zggz[i].wages_payable);
		scanf("%f\t",&zggz[i].personal_income_tax);
		scanf("%f\t",&zggz[i].real_salary);
		//newemp.wage3=newemp.wage1+newemp.wage2+newemp.funds-newemp.WATERfee-newemp.TAXfee;//获取一个新的职工记录 
		fwrite(&zggz,sizeof(struct worker),1,fp);
	} 
	fclose(fp); 
}
void del(struct worker zggz[])//删除职工工资数据函数
{
	FILE *fp;
	int i,j,n;
	char gonghao[20];
	if((fp=fopen("gx","rb"))==NULL)
	{
		printf("不能打开gx文件\n");
		exit(1);
	}
	printf("要删除的工号");
	scanf("%c",gonghao);
	for(i=0;(strcmp(zggz[i].workernumber,gonghao)!=0&&i<n);i++)
		if(i>=n)
		{
			printf("\t没有%c工号的职工\n",gonghao);
			exit(2);
		}
		fclose(fp);
		fp=fopen("gx.dat","w+");
		if(n==1)//该工号的职工工资数据已删除
		{
			fclose(fp);
			exit(3);
		}
		for(j=0;j<i;j++)
		{
			fwrite(&zggz[j],sizeof(strcmp worker),1,fp);
			fseek(fp,0,SEEK_SET);
			printf("工号\t姓名\t岗位工资\t薪级工资\t职务津贴\t绩效工资\t应发工资\t个人所得税\t实发工资\n");
			for(i=0;fread(&zggz[i],sizeof(struct worker),1,fp);i++)
			{
				printf("%c\t",zggz[i].workernumber);
	     	    printf("%c\t",zggz[i].name);
	         	printf("%f\t",zggz[i].post_salary);
	        	printf("%f\t",zggz[i].pay_wages);
	     	    printf("%f\t",zggz[i].post_allowance);
	    	    printf("%f\t",zggz[i].performance_salary);
	    	    printf("%f\t",zggz[i].wages_payable);
	    	    printf("%f\t",zggz[i].personal_income_tax);
	    	    printf("%f\t",zggz[i].real_salary);
			}
			fclose(fp);
		}
}
int main()
{  
	struct worker zggz[50];
	int choose;//选择按钮
	read(struct worker zggz[]);
	write(struct worker zggz[],int n);
	find(struct worker zggz[],int n);
	list(struct worker zggz[],int n);
	modify(struct worker zggz[],int n);
	del(struct worker zggz[],int n);
	add(struct worker zggz[],int n);
	grsds(struct worker zggz[]);
	n=readfile(zggz);//调用读入函数
	puts("\n");
	puts("    工资管理系统    ");
	puts("/n");
	//do_while循环实现循环此功能
	do
	{
		printf("/n");
		system("pause");
		system("cls");//清屏
		puts("    功能选择菜单    ");
		puts("/n");
		puts("    1、查询员工信息    ");
		puts("    2、浏览员工信息    ");
		puts("    3、修改员工信息    ");
		puts("    4、添加员工信息    ");
		puts("    5、删除员工信息    ");
		puts("    6、保存员工信息    ");
		puts("    7、退出程序    ");
		printf("/n");
		printf("请输入你的选择：");
		scanf("%d",&choose);
		switch(choose)
		{
		case 1:
			find(zggz);
			break;
		case 2:
			list(zggz);
			break;
		case 3:
			modify(zggz);
			break;
		case 4:
			add(zggz);
			break;
		case 5:
			del(zggz);
			break;
		case 6:
			write(zggz);
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
	return 0;

}