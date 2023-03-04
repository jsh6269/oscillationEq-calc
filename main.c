#include <stdio.h>
#include <math.h>
double s,p,q;
double c1,c2;
struct coefficient1{
    double cx1;
    double cy1;
    double cx2;
    double cy2;
    double rest1;
    double rest2;
};
struct coefficient2{
    double c2;
    double c1;
    double c0;
};
struct coefficientfinal{
    double cf1;
    double cf2;
    double cf3;
    double cf4;
    double cf5;
    double cf6;
};

struct coefficient1 get1;
struct coefficient2 get2;
struct coefficientfinal get3;

int determine()
{
    double d;
    d=get2.c1*get2.c1-4*get2.c0*get2.c2;
    if(d<0)
        return 1;
    else if(d==0)
        return 2;
    else
        return 3;
}
void solveequation2()
{
    double d;
    d=get2.c1*get2.c1-4*get2.c0*get2.c2;
    if(d==0)
    {
        s=-get2.c1/(2*get2.c2);
    }
    else if (d>0)
    {
        s=(-get2.c1+pow(d,0.5))/(2*get2.c2);
        p=(-get2.c1-pow(d,0.5))/(2*get2.c2);
    }
    return;
}
void solveequation1()
{
    c2=(get1.rest1*get1.cx2-get1.cx1*get1.rest2)/(get1.cy1*get1.cx2-get1.cx1*get1.cy2);
    c1=(get1.rest1-get1.cy1*c2)/get1.cx1;
}
void normal()
{
    double x1,x2,t1,t2;
    solveequation2();
    //x(t)=c1e^st+c2e^pt
    printf("\n ���δٸ� 2���� �ʱ������� �Է��ϼž��մϴ�. ");
    printf("\n t1 = ? x1 = ? ");
    scanf("%lf %lf",&t1,&x1);
    printf(" t2 = ? x2 = ? ");
    scanf("%lf %lf",&t2,&x2);
    get1.cx1=exp(s*t1);
    get1.cy1=exp(p*t1);
    get1.cx2=exp(s*t2);
    get1.cy2=exp(p*t2);
    get1.rest1=x1;
    get1.rest2=x2;
    solveequation1();
    if(c2<0)
        printf("\n  X(t)=%lf*e^(%lf*t)%lf*e^(%lf*t)\n",c1,s,c2,p);
    else
        printf("\n  X(t)=%lf*e^(%lf*t)+%lf*e^(%lf*t)\n",c1,s,c2,p);
    printf("\nover damping\n");
    if(c2*p>=0)
        printf("\n  v(t)=%lf*e^(%lf*t)+%lf*e^(%lf*t)\n",c1*s,s,c2*p,p);
    else
         printf("\n  v(t)=%lf*e^(%lf*t)%lf*e^(%lf*t)\n",c1*s,s,c2*p,p);

    if(c2*p*p>=0)
        printf("\n  a(t)=%lf*e^(%lf*t)+%lf*e^(%lf*t)\n",c1*s*s,s,c2*p*p,p);
    else
         printf("\n  a(t)=%lf*e^(%lf*t)%lf*e^(%lf*t)\n",c1*s*s,s,c2*p*p,p);

    get3.cf1=c1;
    get3.cf2=c2;
    get3.cf3=c1*s;
    get3.cf4=c2*p;
    get3.cf5=c1*s*s;
    get3.cf6=c2*p*p;
}
void overlap()
{
    double x1,x2,t1,t2;
    solveequation2();
    //x(t)=c1e^st+c2te^st
    printf("\n ���δٸ� 2���� �ʱ������� �Է��ϼž��մϴ�. ");
    printf("\n t1 = ? x1 = ? ");
    scanf("%lf %lf",&t1,&x1);
    printf(" t2 = ? x2 = ? ");
    scanf("%lf %lf",&t2,&x2);
    get1.cx1=exp(s*t1);
    get1.cy1=t1*exp(s*t1);
    get1.cx2=exp(s*t2);
    get1.cy2=t2*exp(s*t2);
    get1.rest1=x1;
    get1.rest2=x2;
    solveequation1();
    if(c2<0)
        printf("\n  X(t)=%lf*e^(%lf*t)%lf*t*e^(%lf*t)\n",c1,s,c2,s);
    else
        printf("\n  X(t)=%lf*e^(%lf*t)+%lf*t*e^(%lf*t)\n",c1,s,c2,s);
    printf("\ncritical damping\n");
    if(c2*s<0)
        printf("\n  v(t)=%lf*e^(%lf*t)%lf*t*e^(%lf*t)\n",c1*s+c2,s,c2*s,s);
    else
        printf("\n  v(t)=%lf*e^(%lf*t)+%lf*t*e^(%lf*t)\n",c1*s+c2,s,c2*s,s);

    if(c2*s*s<0)
        printf("\n  a(t)=%lf*e^(%lf*t)%lf*t*e^(%lf*t)\n",c1*s*s+c2*s*2,s,c2*s*s,s);
    else
        printf("\n  a(t)=%lf*e^(%lf*t)+%lf*t*e^(%lf*t)\n",c1*s*s+c2*s*2,s,c2*s*s,s);
    get3.cf1=c1;
    get3.cf2=c2;
    get3.cf3=c1*s+c2;
    get3.cf4=c2*s;
    get3.cf5=c1*s*s+c2*s*2;
    get3.cf6=c2*s*s;
}
void period()
{
    double x1,x2,t1,t2;
    p=-get2.c1/(2*get2.c2);
    q=pow(4*get2.c2*get2.c0-get2.c1*get2.c1,0.5)/(2*get2.c2);
    printf("\n ���δٸ� 2���� �ʱ������� �Է��ϼž��մϴ�. ");
    printf("\n t1 = ? x1 = ? ");
    scanf("%lf %lf",&t1,&x1);
    printf(" t2 = ? x2 = ? ");
    scanf("%lf %lf",&t2,&x2);
    get1.cx1=exp(p*t1)*cos(q*t1);
    get1.cx2=exp(p*t2)*cos(q*t2);
    get1.cy1=exp(p*t1)*sin(q*t1);
    get1.cy2=exp(p*t2)*sin(q*t2);
    get1.rest1=x1;
    get1.rest2=x2;
    solveequation1();
    printf("\n������ rad�����Դϴ�.(������ �ƴ�!)\n");
    if(c2<0)
        printf("\n  X(t)=(e^(%lft))*(%lfcos(%lf*t)%lfsin(%lf*t))\n",p,c1,q,c2,q);
    else
        printf("\n  X(t)=(e^(%lft))*(%lfcos(%lf*t)+%lfsin(%lf*t))\n",p,c1,q,c2,q);
    printf("\nunder damping\n");

    if(c2*p-q*c1<0)
        printf("\n  v(t)=(e^(%lft))*(%lfcos(%lf*t)%lfsin(%lf*t))\n",p,c1*p+q*c2,q,c2*p-q*c1,q);
    else
        printf("\n  v(t)=(e^(%lft))*(%lfcos(%lf*t)+%lfsin(%lf*t))\n",p,c1*p+q*c2,q,c2*p-q*c1,q);

    if(c2*p*p-2*p*q*c1-q*q*c2<0)
        printf("\n  a(t)=(e^(%lft))*(%lfcos(%lf*t)%lfsin(%lf*t))\n",p,c1*p*p+2*q*c2*p-q*q*c1,q,c2*p*p-2*p*q*c1-q*q*c2,q);
    else
        printf("\n  a(t)=(e^(%lft))*(%lfcos(%lf*t)+%lfsin(%lf*t))\n",p,c1*p*p+2*q*c2*p-q*q*c1,q,c2*p*p-2*p*q*c1-q*q*c2,q);
    get3.cf1=c1;
    get3.cf2=c2;
    get3.cf3=c1*p+q*c2;
    get3.cf4=c2*p-q*c1;
    get3.cf5=c1*p*p+2*q*c2*p-q*q*c1;
    get3.cf6=c2*p*p-2*p*q*c1-q*q*c2;
}
int main()
{
    int choice;
    char choose[20];
    printf("\n �м��ϰ����ϴ� (����)�Ŀ��� ����� �Է����ּ���.\n\n");
    printf(" a*(d^2x/dt)+b*(dx/dt)+c*x=0  \n\n a = ? ");
    scanf("%lf",&get2.c2);
    printf(" b = ? ");
    scanf("%lf",&get2.c1);
    printf(" c = ? ");
    scanf("%lf",&get2.c0);
    choice=determine();
    switch(choice)
    {
        case 3:
            normal(); break;
        case 2:
            overlap(); break;
        default:
            period(); break;
    }
    printf("\n�������� Ʋ�� �� ���ٸ� press 1 �������̶�� press 0\n\n");
    scanf("%s",choose);
    while(1){

    if(!strcmp(choose,"1"))
    {
        printf("\n\n");
        printf(" 1. #INFO�� ��ٸ� ��������� ���� ���� �ʴ� �ʱ����� ������ �� �ֽ��ϴ�. ex)2���϶� 3m 2���϶� 5m");
        printf("\n �Ǵ� ���� �ʱ������� 2�� ��� ������ �� �ֽ��ϴ�.  ex)2�� 3m, 2�� 3m\n\n");
        printf("2. �����Ŀ� �����ϴ� �������� �ʴ� ���: e�� ������ ū ��� �Ҽ��� 6°�ڸ� ����δ� ������ �� �ֽ��ϴ�.\n");
        printf("������ ������ rad�����ε� �������� �����ϼ��� �� �ֽ��ϴ�. ����� ������ �� Ư�� ����\n");
        printf("�Ǵ� ���̳� ����� �Ϻθ� �߸� �о��� �� �ֽ��ϴ�. �ణ�� ���̷ε� ���� ũ�� ���մϴ�.\n\n");
        printf("���Ḧ ���� �� 1���� �ƹ��ų� ��������.\n\n");
        scanf("%s",choose);
        break;
    }
    else if(!strcmp(choose,"0"))
        break;
    else{
        printf("\n�߸��Է��ϼ̽��ϴ�. �ٽ� �Է����ּ���.\n");
        scanf("%s",choose);
    }
    }
    if(!strcmp(choose,"1"))
    {
        printf("\n%.30lf\n%.30lf\n%.30lf\n%.30lf\n%.30lf\n%.30lf\n",get3.cf1,get3.cf2,get3.cf3,get3.cf4,get3.cf5,get3.cf6);
        if(choice==3)
            printf("%.30lf\n%.30lf",s,p);
        else if(choice==2)
            printf("%.30lf\n",s);
        else
            printf("%.30lf\n%.30lf",p,q);
    }
    return 0;
}
