/////////////////////////////////////////////////////////////////////////////////
//
//
//
//
/////////////////////////////////////////////////////////////////////////////////
#include <Stdio.h>
#include "CommonAPI.h"
#include "LessonX.h"
int time=0;
int state;
int t1,t2,t3;
char deadman[100];
float fleadx,fleady;
int yon=0;
int life=3;
int lifestate=0;
int next=0;
int k=0;
int zjy;
int dead=0;
int kkk=0;
int jjj=0;
int cure_1=0;
int cure_2=0;
float rp1,rp2;
float rpp1,rpp2;
////////////////////////////////////////////////////////////////////////////////
//
//
int			g_iGameState		=	0;		// ��Ϸ״̬��0 -- ��Ϸ�����ȴ���ʼ״̬��1 -- ���¿ո����ʼ����ʼ����Ϸ��2 -- ��Ϸ������
//
void		GameInit();
void		GameRun( float fDeltaTime );
void		GameEnd();

//==============================================================================
//
// ����ĳ�������Ϊ��GameMainLoop����Ϊ��ѭ��������������ÿ֡ˢ����Ļͼ��֮�󣬶��ᱻ����һ�Ρ�


//==============================================================================
//
// ��Ϸ��ѭ�����˺���������ͣ�ĵ��ã�����ÿˢ��һ����Ļ���˺�����������һ��
// ���Դ�����Ϸ�Ŀ�ʼ�������С������ȸ���״̬.
// ��������fDeltaTime : �ϴε��ñ��������˴ε��ñ�������ʱ��������λ����
void GameMainLoop( float	fDeltaTime )
{
	switch( g_iGameState )
	{
		// ��ʼ����Ϸ�������һ���������
	case 1:
		{
			GameInit();
			g_iGameState	=	2; // ��ʼ��֮�󣬽���Ϸ״̬����Ϊ������
		}
		break;

		// ��Ϸ�����У����������Ϸ�߼�
	case 2:
		{
			// TODO �޸Ĵ˴���Ϸѭ�������������ȷ��Ϸ�߼�
			if( true )
			{
				GameRun( fDeltaTime );
			}
			else
			{
				// ��Ϸ������������Ϸ���㺯����������Ϸ״̬�޸�Ϊ����״̬
				g_iGameState	=	0;
				GameEnd();
			}
		}
		break;

		// ��Ϸ����/�ȴ����ո����ʼ
	case 0:
	default:
		break;
	};
}

//==============================================================================
//
// ÿ�ֿ�ʼǰ���г�ʼ���������һ���������
void GameInit()
{
state=0;
dSetSpriteWorldLimit("redman1",WORLD_LIMIT_BOUNCE,10.022,-26.642,26.741,-11.642);

g_iGameState=2;
dSpriteMoveTo("redman2",-8.55,-1.79,0.5,1);
dSetSpriteLinearVelocity("redman1",0.5,-0.5);
dSetSpriteLinearVelocity("pb1",2,2);
dSetSpriteLinearVelocity("pb2",0,0);
}
//==============================================================================
//
// ÿ����Ϸ������
void GameRun( float fDeltaTime )
{
//life expectancy
if(life==3&&lifestate==0)
{
    dCloneSprite("l3","c1");
    dSetSpritePosition("c1",-40,-35);
    lifestate=1;
}
if(life==2&&lifestate==1)
{
    dDeleteSprite("c1");
    dCloneSprite("l2","c2");
    dSetSpritePosition("c2",-40,-35);
    lifestate=2;
}
if(life==1&&lifestate==2)
{
    dDeleteSprite("c2");
    dCloneSprite("l1","c3");
    dSetSpritePosition("c3",-40,-35);
    lifestate=3;
}
if(life<1)
{
    dDeleteSprite("c3");
    dCloneSprite("die","p1");
    dSetSpritePosition("p1",0,0);
    dead=1;
    state=0;
}
}
//==============================================================================
//
// ������Ϸ����
void GameEnd()
{

}
//==========================================================================
//
// ����ƶ�
// ���� fMouseX, fMouseY��Ϊ��굱ǰ����
void OnMouseMove( const float fMouseX, const float fMouseY )
{

}
//==========================================================================
//
// �����
// ���� iMouseType����갴��ֵ���� enum MouseTypes ����
// ���� fMouseX, fMouseY��Ϊ��굱ǰ����
void OnMouseClick( const int iMouseType, const float fMouseX, const float fMouseY )
{
	dSpriteMoveTo("Leadman",fMouseX,fMouseY,5,1);

}
//==========================================================================
//
// ��굯��
// ���� iMouseType����갴��ֵ���� enum MouseTypes ����
// ���� fMouseX, fMouseY��Ϊ��굱ǰ����
void OnMouseUp( const int iMouseType, const float fMouseX, const float fMouseY )
{

if(fMouseX<=-31&&fMouseX >=-35&&fMouseY>=-14&&fMouseY<=-10&&jjj==0)
{
    dCloneSprite("T1","copy4");
    dSetSpritePosition("copy4",0,0);
    state=1;

}
if(fMouseX<=-13&&fMouseX>=-16&&fMouseY<=-26&&fMouseY>=-30&&kkk==0)
{
    dCloneSprite("T5","copy37");
    dSetSpritePosition("copy37",0,0);
    state=2;
}
if(fMouseX<=6&&fMouseX>=2&&fMouseY<=32&&fMouseY>=28&&cure_1==1)
{
    rp1=dGetSpritePositionX("redman1");//x
    rp2=dGetSpritePositionY("redman1");//y

    dSetSpriteLinearVelocity("redman1",0,0);
    dDeleteSprite("redman1");
    dCloneSprite("cure","q1");
    dSetSpritePosition("q1",rp1,rp2);

}
if(fMouseX<=29&&fMouseX>=25&&fMouseY<=-23&&fMouseY>=-27&&cure_2==1)
{
    rpp1=dGetSpritePositionX("redman2");//x
    rpp2=dGetSpritePositionY("redman2");//y

    dSetSpriteLinearVelocity("redman2",0,0);
    dDeleteSprite("redman2");
    dCloneSprite("cure","q2");
    dSetSpritePosition("q2",rpp1,rpp2);

}
}
//==========================================================================
//
// ���̰���
// ���� iKey�������µļ���ֵ�� enum KeyCodes �궨��
// ���� iAltPress, iShiftPress��iCtrlPress�������ϵĹ��ܼ�Alt��Ctrl��Shift��ǰ�Ƿ�Ҳ���ڰ���״̬(0δ���£�1����)
void OnKeyDown( const int iKey, const bool bAltPress, const bool bShiftPress, const bool bCtrlPress )
{
if(iKey==KEY_G)
{
    next=1;//press key-shift to enter next quiz
    k=0;// clear
}
if(iKey==KEY_1)
{
    k=1;
}
if(iKey==KEY_2)
{
    k=2;
}
if(iKey==KEY_SPACE)
{
time++;
g_iGameState=1;
}
if(time==1)
        {dCloneSprite("story","copy1");
    dSetSpritePosition("copy1",0,0);}
if(time==2)
{
    dDeleteSprite("copy1");
    dCloneSprite("intro","copy2");
    dSetSpritePosition("copy2",0,0);
}
if(time==3)
 {
     dDeleteSprite("copy2");

    }

if(state==1&&yon==0)  //t1=judge
{
    if(k==2)
    {
    next=0;
    dCloneSprite("yep","copy103");
    dSetSpritePosition("copy103",0,0);
    yon=1;//���Խ�����һ����Ŀ
    dCloneSprite("G","cp1");
    dSetSpritePosition("cp1",0,25);
    }

    else if(k==1)
    {
    next=0;
    dCloneSprite("nope","copy104");
    dSetSpritePosition("copy104",0,0);
    yon=1;
//����ֵ-1/�ܹ�����
    life--;
    dCloneSprite("G","cp2");
    dSetSpritePosition("cp2",0,25);
    }}
if(state==1&&yon==1&&next==1)//t2=show
{
    dDeleteSprite("cp1");
    dDeleteSprite("cp2");
    dDeleteSprite("copy104");
    dDeleteSprite("copy103");
    dDeleteSprite("copy4");

    dCloneSprite("T2","copy10");
    dSetSpritePosition("copy10",0,0);
    yon=2;
    next=0;
}
if(state==1&&yon==2)//t2=judge
{
    if(k==1)
    {
    next=0;
    dCloneSprite("yep","copy100");
    dSetSpritePosition("copy100",0,0);
    yon=3;//���Խ�����һ����Ŀ
    dCloneSprite("G","cp3");
    dSetSpritePosition("cp3",0,25);
    }

    else if(k==2)
    {
    next=0;
    dCloneSprite("nope","copy101");
    dSetSpritePosition("copy101",0,0);
    yon=3;
//����ֵ-1/�ܹ�����
dCloneSprite("G","cp4");
    dSetSpritePosition("cp4",0,25);
    life--;
    }}
if(state==1&&yon==3&&next==1)//t3=show
{
    jjj=1;
    dDeleteSprite("cp3");
    dDeleteSprite("cp4");

    dDeleteSprite("copy100");
    dDeleteSprite("copy101");
    dDeleteSprite("copy10");

    dCloneSprite("T3","copy11");
    dSetSpritePosition("copy11",0,0);
    yon=4;

}

if(state==1&&yon==4)//t3=judge
{
    if(k==1)
    {
    next=0;
    dCloneSprite("yep","copy105");
    dSetSpritePosition("copy105",0,0);
    yon=5;//���Խ�����һ����Ŀ
    dCloneSprite("G","cp5");
    dSetSpritePosition("cp5",0,25);
    }

    else if(k==2)
    {
    next=0;
    dCloneSprite("nope","copy106");
    dSetSpritePosition("copy106",0,0);
    yon=5;
//����ֵ-1/�ܹ�����
    life--;
    dCloneSprite("G","cp6");
    dSetSpritePosition("cp6",0,25);
    }

}
if(state==1&&yon==5&&next==1)//t4=show
{


printf("1  ");
    dDeleteSprite("cp6");
    dDeleteSprite("cp5");
    dDeleteSprite("copy11");
    dDeleteSprite("copy105");
    dDeleteSprite("copy106");

    dCloneSprite("T4","copy12");
    dSetSpritePosition("copy12",0,0);
    yon=6;

}
if(state==1&&yon==6)//t4=judge
{
    if(k==1)
    {printf("2  ");
    next=0;
    dCloneSprite("yep","copy110");
    dSetSpritePosition("copy110",0,0);
    yon=7;//���Խ�����һ����Ŀ
    dCloneSprite("G","cp7");
    dSetSpritePosition("cp8",0,25);
    }

    else if(k==2)
    {
    next=0;
    dCloneSprite("nope","copy120");
    dSetSpritePosition("copy120",0,0);
    yon=7;
//����ֵ-1/�ܹ�����
    life--;
    dCloneSprite("G","cp7");
    dSetSpritePosition("cp8",0,25);
    }}
if(state==1&&yon==7&&next==1)//end
{
    printf("3");
    dDeleteSprite("cp7");
    dDeleteSprite("cp8");
   dDeleteSprite("copy110");
   dDeleteSprite("copy120");
   dDeleteSprite("copy12");
   //do sthing
   yon=8;
   dCloneSprite("med","m1");
   dSetSpritePosition("m1",4.072,30.602);
   cure_1=1;
}
if(state==2&&zjy==0)  //t1=judge////////////////////////////////////////////
{
    if(k==2)
    {
    next=0;
    dCloneSprite("yep","copy203");
    dSetSpritePosition("copy203",0,0);
    zjy=1;//���Խ�����һ����Ŀ
    dCloneSprite("G","cp9");
    dSetSpritePosition("cp9",0,25);
    }

    else if(k==1)
    {
    next=0;
    dCloneSprite("nope","copy204");
    dSetSpritePosition("copy204",0,0);
    zjy=1;
//����ֵ-1/�ܹ�����
    life--;
    dCloneSprite("G","cp10");
    dSetSpritePosition("cp10",0,25);
    }}
if(state==2&&zjy==1&&next==1)//t2=show
{
    kkk=1;
    dDeleteSprite("cp10");
    dDeleteSprite("cp9");
    dDeleteSprite("copy204");
    dDeleteSprite("copy203");
    dDeleteSprite("copy37");

    dCloneSprite("T6","copy30");
    dSetSpritePosition("copy30",0,0);
    zjy=2;
    next=0;
}
if(state==2&&zjy==2)//t2=judge
{
    if(k==1)
    {
    next=0;
    dCloneSprite("yep","copy200");
    dSetSpritePosition("copy200",0,0);
    zjy=3;//���Խ�����һ����Ŀ
    dCloneSprite("G","cp11");
    dSetSpritePosition("cp11",0,25);
    }

    else if(k==2)
    {
    next=0;
    dCloneSprite("nope","copy201");
    dSetSpritePosition("copy201",0,0);
    zjy=3;
//����ֵ-1/�ܹ�����
    life--;
    dCloneSprite("G","cp12");
    dSetSpritePosition("cp12",0,25);
    }}
if(state==2&&zjy==3&&next==1)//t3=show
{
    dDeleteSprite("cp11");
    dDeleteSprite("cp12");


    dDeleteSprite("copy200");
    dDeleteSprite("copy201");
    dDeleteSprite("copy30");

    dCloneSprite("T7","copy31");
    dSetSpritePosition("copy31",0,0);
    zjy=4;

}

if(state==2&&zjy==4)//t3=judge
{
    if(k==1)
    {
    next=0;
    dCloneSprite("yep","copy205");
    dSetSpritePosition("copy205",0,0);
    zjy=5;//���Խ�����һ����Ŀ
    dCloneSprite("G","cp13");
    dSetSpritePosition("cp13",0,25);
    }

    else if(k==2)
    {
    next=0;
    dCloneSprite("nope","copy206");
    dSetSpritePosition("copy206",0,0);
    zjy=5;
//����ֵ-1/�ܹ�����
    life--;
    dCloneSprite("G","cp14");
    dSetSpritePosition("cp14",0,25);
    }

}
if(state==2&&zjy==5&&next==1)//t4=show
{
    dDeleteSprite("cp13");
    dDeleteSprite("cp14");

printf("1  ");
    dDeleteSprite("copy31");
    dDeleteSprite("copy205");
    dDeleteSprite("copy206");

    dCloneSprite("T8","copy32");
    dSetSpritePosition("copy32",0,0);
    zjy=6;

}
if(state==2&&zjy==6)//t4=judge
{
    if(k==1)
    {printf("2  ");
    next=0;
    dCloneSprite("yep","copy210");
    dSetSpritePosition("copy210",0,0);
    zjy=7;//���Խ�����һ����Ŀ
    dCloneSprite("G","cp15");
    dSetSpritePosition("cp15",0,25);
    }

    else if(k==2)
    {
    next=0;
    dCloneSprite("nope","copy220");
    dSetSpritePosition("copy220",0,0);
    zjy=7;
//����ֵ-1/�ܹ�����
    life--;
    dCloneSprite("G","cp16");
    dSetSpritePosition("cp16",0,25);
    }}
if(state==2&&zjy==7&&next==1)//end
{
    dDeleteSprite("cp15");
    dDeleteSprite("cp16");
    printf("3");
   dDeleteSprite("copy210");
   dDeleteSprite("copy220");
   dDeleteSprite("copy32");
   //do sthing
   zjy=8;
   dCloneSprite("med","m2");
   dSetSpritePosition("m2",27.589,-25.166);
   cure_2=1;
}
}


//==========================================================================
//
// ���̵���
// ���� iKey������ļ���ֵ�� enum KeyCodes �궨��
void OnKeyUp( const int iKey )
{

}
//===========================================================================
//
// �����뾫����ײ
// ���� szSrcName��������ײ�ľ�������
// ���� szTarName������ײ�ľ�������
void OnSpriteColSprite( const char *szSrcName, const char *szTarName )
{
float fx,fy;

  if(g_iGameState==2)
  {
  if(strstr(szSrcName,"redman")!=0&&strstr(szTarName,"blackman")!=0)
  {


      strcpy(deadman,szTarName);


      fx=dGetSpritePositionX(deadman);
      fy=dGetSpritePositionY(deadman);


      dCloneSprite("redmodel","red1");
      dDeleteSprite(szTarName);
      dSetSpritePosition("red1",fx,fy);
    dCloneSprite("die","o1");
    dSetSpritePosition("o1",0,0);

  }
}}

//===========================================================================
//
// ����������߽���ײ
// ���� szName����ײ���߽�ľ�������
// ���� iColSide����ײ���ı߽� 0 ��ߣ�1 �ұߣ�2 �ϱߣ�3 �±�
void OnSpriteColWorldLimit( const char *szName, const int iColSide )
{

}
