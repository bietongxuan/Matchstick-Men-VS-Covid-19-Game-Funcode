/////////////////////////////////////////////////////////////////////////////////
//
//
//
//
/////////////////////////////////////////////////////////////////////////////////
#include <Stdio.h>
#include "CommonAPI.h"
#include "LessonX.h"

#include <math.h>
int shuju =0;

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
int num_0;
int         num                 =   0;
//����̹�˷��������ȫ�ֱ���
int         time_A              =   0;
int         time_B              =   0;
//���þ���λ�������ȫ�ֱ���
float       t_PositionX_1;
float       t_PositionX_2;
float       t_PositionX_3;
//������ʾ����״̬
int         wu_state_1;
int         wu_state_2;
int         wu_state_3;
//�����ڵ�λ�û�ȡ��ȫ�ֱ���
float       fPosX_1;
float       fPosY_1;
float       fPosX_2;
float       fPosY_2;
float       fPosX_3;
float       fPosY_3;
//��������λ��
float       w_fPosX_1;
float       w_fPosX_2;
float       w_fPosX_3;
//A.B�˶��ٶȵ�ȫ�ֱ���
float		g_fSpeedLeft_A		=	0.f;  	// �����ٶ�
float		g_fSpeedRight_A		=	0.f;  	// ��
float		g_fSpeedTop_A		    =	0.f;  	// ��
float		g_fSpeedBottom_A	    =	0.f;  	// ��
float		g_fSpeedLeft_B		=	0.f;  	// �����ٶ�
float		g_fSpeedRight_B		=	0.f;  	// ��
float		g_fSpeedTop_B		    =	0.f;  	// ��
float		g_fSpeedBottom_B	    =	0.f;  	// ��
//��ȡ����߽��ȫ�ֱ���
float       g_fScreenLeft  ;
float       g_fScreenRight   ;
float       g_fScreenTop       ;
float       g_fScreenBottom    ;
//
//����÷�
int         number=0;
int         score_big=0;
int         score_small=0;
int         score_all=0;

//������Ϸ������־��ȫ�ֱ���
int         game_flag;

//����ʱ������
float         time_left=25;
float		g_fSpeedLeft		=	0.f;  	// �����ٶ�
float		g_fSpeedRight	=	0.f;  	// ��
float		g_fSpeedTop		    =	0.f;  	// ��
float		g_fSpeedBottom	    =	0.f;  	// ��
//��ȡ����߽��ȫ�ֱ���
//float       g_fScreenLeft  ;
//float       g_fScreenRight   ;
//float       g_fScreenTop       ;
//float       g_fScreenBottom    ;

float        fPosX;
float        fPosY;

int         circle=0;
int         n=0;
int         flag=0;
//������Ϸ������־��ȫ�ֱ���
int         game_flag_2;

//����ʱ������
float         Time_left=60;
////////////////////////////////////////////////////////////////////////////////
//
//
//float		g_fSpeedLeft		=	0.f;  	// �����ٶ�
//float		g_fSpeedRight	=	0.f;  	// ��
//float		g_fSpeedTop		    =	0.f;  	// ��
//float		g_fSpeedBottom	    =	0.f;  	// ��
//��ȡ����߽��ȫ�ֱ���
//float       g_fScreenLeft  ;
//float       g_fScreenRight   ;
//float       g_fScreenTop       ;
//float       g_fScreenBottom    ;

//float        fPosX;
//float        fPosY;
//
//int         circle=0;


//������Ϸ������־��ȫ�ֱ���


//����ʱ������


int			g_iGameState=0;		// ��Ϸ״̬��0 -- ��Ϸ�����ȴ���ʼ״̬��1 -- ���¿ո����ʼ����ʼ����Ϸ��2 -- ��Ϸ������
//
void		GameInit();
void		GameRun( float fDeltaTime );
void		GameEnd();

void        TimeLimit_2( float fDeltaTime );
void        TimeLimit_3(float fDeltaTime);
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
    if(shuju ==0&&g_iGameState>=0&&g_iGameState<=2)
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
        if(g_iGameState==0)
            g_iGameState=3;


        // ��Ϸ����/�ȴ����ո����ʼ
        case 0:
        default:
            break;

        };

    }
    if(shuju == 1&&g_iGameState>=0&&g_iGameState<=2)
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

        g_iGameState=6;

        // ��Ϸ����/�ȴ����ո����ʼ
        case 0:
        default:
            break;
        };
    }
    if(shuju == 2)
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

            if( game_flag_2 == 0 )
            {
                TimeLimit_2( fDeltaTime );
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
    if(shuju == 3)
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
            if( game_flag == 0 )
            {

                TimeLimit_3( fDeltaTime );
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

}

//==============================================================================
//
// ÿ�ֿ�ʼǰ���г�ʼ���������һ���������
void    TimeLimit_2( float fDeltaTime )
{

    Time_left -= fDeltaTime;
    dSetTextValue( "time_left", Time_left );

    if(n >= 5 && flag==1 )
    {
        game_flag_2   =   1;
    }
    else if(Time_left <= 0 && ( n<5 || flag==0 ))
    {
        game_flag_2   =   2;
    }



}
void TimeLimit_3(float fDeltaTime)
{
    time_left -= fDeltaTime;
    dSetTextValue( "time_text", time_left );
    //if(time_left <= 10&&time_left > 0)
    //dPlaySound("ten.ogg", 0, 1 );

    if(time_left <= 0 && score_all >= 50)
    {
        game_flag   =   1;
    }
    if(time_left <=0 && score_all < 50)
    {
        game_flag   =   2;
    }
}


void GameInit()
{
    if(shuju == 0)
    {
        dPlaySound("Lifting.ogg",1,1);
    }

    if(shuju == 1&&g_iGameState>=0&&g_iGameState<=2)
    {
        state=0;
        dSetSpriteWorldLimit("redman1",WORLD_LIMIT_BOUNCE,10.022,-26.642,26.741,-11.642);

        g_iGameState=2;
        dSpriteMoveTo("redman2",-8.55,-1.79,0.5,1);
        dSetSpriteLinearVelocity("redman1",0.5,-0.5);
        dSetSpriteLinearVelocity("pb1",2,2);
        dSetSpriteLinearVelocity("pb2",0,0);
    }
    if(shuju == 2)
    {
        game_flag_2 = 0;

        g_fScreenLeft       =   dGetScreenLeft();
        g_fScreenRight      =   dGetScreenRight();
        g_fScreenTop        =   dGetScreenTop();
        g_fScreenBottom     =   dGetScreenBottom();
        dSetSpriteWorldLimit("man", WORLD_LIMIT_NULL, g_fScreenLeft, g_fScreenTop, g_fScreenRight, g_fScreenBottom);

        //dPlaySound("Lifting.ogg",1,1);
        dSetSpriteVisible("jieshao",1);

        dSetSpriteCollisionActive( "man",1, 1 );
        dSetSpriteCollisionPhysicsReceive( "wall_1", 1 );
        dSetSpriteCollisionPhysicsReceive( "wall_2", 1 );
        dSetSpriteCollisionPhysicsReceive( "wall_3", 1 );
        dSetSpriteCollisionPhysicsReceive( "wall_4", 1 );
        dSetSpriteCollisionPhysicsReceive( "wall_5", 1 );

        fPosX = dGetSpritePositionX( "logo" );
        fPosY = dGetSpritePositionY( "logo" );
    }
    if(shuju == 3)
    {
        //��Ϸ��־��ʼ��
        game_flag   =   0;

        g_fScreenLeft       =   dGetScreenLeft();
        g_fScreenRight      =   dGetScreenRight();
        g_fScreenTop        =   dGetScreenTop();
        g_fScreenBottom     =   dGetScreenBottom();
        dSetSpriteWorldLimit("A_man", WORLD_LIMIT_NULL, g_fScreenLeft, g_fScreenTop, g_fScreenRight, g_fScreenBottom);
        dSetSpriteWorldLimit("B_man", WORLD_LIMIT_NULL, g_fScreenLeft, g_fScreenTop, g_fScreenRight, g_fScreenBottom);
        //���þ����ܷ������ײ��ײ
        //Χǽ
        dSetSpriteCollisionPhysicsReceive( "barrier_1", 1 );
        dSetSpriteCollisionPhysicsReceive( "barrier_2", 1 );
        dSetSpriteCollisionPhysicsReceive( "barrier_3", 1 );
        dSetSpriteCollisionPhysicsReceive( "barrier_4", 1 );
        dSetSpriteCollisionPhysicsReceive( "barrier_5", 1 );
        dSetSpriteCollisionPhysicsReceive( "barrier_6", 1 );
        //�����
        dSetSpriteCollisionActive( "A_man",1, 1 );
        dSetSpriteCollisionActive( "B_man",1, 1 );
        //̹��
        dSetSpriteCollisionPhysicsReceive( "tank_1", 1 );
        dSetSpriteCollisionPhysicsReceive( "tank_2", 1 );
        dSetSpriteCollisionPhysicsReceive( "tank_3", 1 );
        //��Һ
        dSetSpriteCollisionActive( "drop_1",1, 1 );
        dSetSpriteCollisionActive( "drop_2",1, 1 );
        dSetSpriteCollisionActive( "drop_3",1, 1 );
        dSetSpriteCollisionActive( "drop_4",1, 1 );
        dSetSpriteCollisionActive( "drop_5",1, 1 );
        dSetSpriteCollisionActive( "drop_6",1, 1 );
        dSetSpriteCollisionActive( "drop_7",1, 1 );
        //��ȡĳЩ����λ������
        t_PositionX_1   =   dGetSpritePositionX( "tank_1" );
        t_PositionX_2   =   dGetSpritePositionX( "tank_2" );
        t_PositionX_3   =   dGetSpritePositionX( "tank_3" );
        //�����ڵ���������
        dSetSpriteConstantForceGravitic("bomb_1", 1 );
        dSetSpriteConstantForceGravitic("bomb_2", 1 );
        dSetSpriteConstantForceGravitic("bomb_3", 1 );
        //��ȡ�ڵ�λ��
        fPosX_1=dGetSpritePositionX( "bomb_1" );
        fPosY_1=dGetSpritePositionY( "bomb_1" );
        fPosX_2=dGetSpritePositionX( "bomb_2" );
        fPosY_2=dGetSpritePositionY( "bomb_2" );
        fPosX_3=dGetSpritePositionX( "bomb_3" );
        fPosY_3=dGetSpritePositionY( "bomb_3" );


        //�󲡶��ĸ���
        {
            for(int i=0; i<2; i++)
            {
                char  szName[128];
                float fPosX, fPosY;
                float fSpeedX;
                sprintf(szName, "b_virus1_%d", i);
                dCloneSprite("Big_Virus_1", szName);
                fPosX = dRandomRange(-50, -45);
                fPosY = dRandomRange(-30, 30);
                dSetSpritePosition(szName, fPosX, fPosY);
                dSetSpriteScale( szName, 0.5 );
                fSpeedX = dRandomRange(3, 5);
                dSetSpriteLinearVelocity(szName, fSpeedX, 0);
                dSetSpriteCollisionActive( "szName",1, 1 );
            }

            for(int i=0; i<2; i++)
            {
                char  szName[128];
                float fPosX, fPosY;
                float fSpeedX;
                sprintf(szName, "b_virus2_%d", i);
                dCloneSprite("Big_virus_2", szName);
                fPosX = dRandomRange(-50, -45);
                fPosY = dRandomRange(-30, 30);
                dSetSpritePosition(szName, fPosX, fPosY);
                dSetSpriteScale( szName, 0.5 );
                fSpeedX = dRandomRange(3, 7);
                dSetSpriteLinearVelocity(szName, fSpeedX, 0);
                dSetSpriteCollisionActive( "szName",1, 1 );
            }

            for(int i=0; i<2; i++)
            {
                char  szName[128];
                float fPosX, fPosY;
                float fSpeedX;
                sprintf(szName, "b_virus3_%d", i);
                dCloneSprite("Big_Virus_3", szName);
                fPosX = dRandomRange(-50, -45);
                fPosY = dRandomRange(-30, 27);
                dSetSpritePosition(szName, fPosX, fPosY);
                dSetSpriteScale( szName, 0.5 );
                fSpeedX = dRandomRange(5, 10);
                dSetSpriteLinearVelocity(szName, fSpeedX, 0);
                dSetSpriteCollisionActive( "szName",1, 1 );
            }
        }
        //С�����ĸ���
        {
            for(int i=0; i<3; i++)
            {
                char  szName[128];
                float fPosX, fPosY;
                float fSpeedX;
                sprintf(szName, "s_virus1_%d", i);
                dCloneSprite("Small_Virus_1", szName);
                fPosX = dRandomRange(-60, -50);
                fPosY = dRandomRange(-30, 30);
                dSetSpritePosition(szName, fPosX, fPosY);
                fSpeedX = dRandomRange(2, 5);
                dSetSpriteLinearVelocity(szName, fSpeedX, 0);
                dSetSpriteCollisionActive( "szName",1, 1 );
            }

            for(int i=0; i<3; i++)
            {
                char  szName[128];
                float fPosX, fPosY;
                float fSpeedX;
                sprintf(szName, "s_virus2_%d", i);
                dCloneSprite("Small_Virus_2", szName);
                fPosX = dRandomRange(-60, -50);
                fPosY = dRandomRange(-30, 30);
                dSetSpritePosition(szName, fPosX, fPosY);
                fSpeedX = dRandomRange(2, 5);
                dSetSpriteLinearVelocity(szName, fSpeedX, 0);
                dSetSpriteCollisionActive( "szName",1, 1 );
            }
            for(int i=0; i<3; i++)
            {
                char  szName[128];
                float fPosX, fPosY;
                float fSpeedX;
                sprintf(szName, "s_virus3_%d", i);
                dCloneSprite("Small_Virus_3", szName);
                fPosX = dRandomRange(-60, -50);
                fPosY = dRandomRange(-30, 30);
                dSetSpritePosition(szName, fPosX, fPosY);
                fSpeedX = dRandomRange(2, 5);
                dSetSpriteLinearVelocity(szName, fSpeedX, 0);
                dSetSpriteCollisionActive( "szName",1, 1 );
            }
        }


    }


}
//==============================================================================
//
// ÿ����Ϸ������
void GameRun( float fDeltaTime )
{
    if(shuju == 1&&g_iGameState>=0&&g_iGameState<=2)
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
    if(shuju == 3)
    {
        //����С�������ٶ�
        float s_fVelX_1 =   dRandomRange( 1, 10 );
        float s_fVelX_2 =   dRandomRange( 1, 10 );
        float s_fVelX_3 =   dRandomRange( 1, 10 );
        float s_fVelX_4 =   dRandomRange( 1, 10 );
        float s_fVelX_5 =   dRandomRange( 1, 10 );

        dSetSpriteLinearVelocity( "Small_Virus_1", s_fVelX_1, 0 );
        dSetSpriteLinearVelocity( "Small_Virus_2", s_fVelX_2, 0 );
        dSetSpriteLinearVelocity( "Small_Virus_3", s_fVelX_3, 0 );
        dSetSpriteLinearVelocity( "Small_Virus_4", s_fVelX_4, 0 );
        dSetSpriteLinearVelocity( "Small_Virus_5", s_fVelX_5, 0 );
        //���ô󲡶����ٶ�
        float b_fVelX_1 =   dRandomRange( 1, 5 );
        float b_fVelX_2 =   dRandomRange( 1, 5 );
        float b_fVelX_3 =   dRandomRange( 1, 5 );
        dSetSpriteLinearVelocity( "Big_Virus_1", b_fVelX_1, 0 );
        dSetSpriteLinearVelocity( "Big_Virus_2", b_fVelX_2, 0 );
        dSetSpriteLinearVelocity( "Big_virus_3", b_fVelX_3, 0 );



        //���õ÷���ʾ
        score_all = score_big + score_small;
        //if(number>0)
        //{
        //score_all -= number;
        //}
        dSetTextValue("score_text",score_all);


        //���ö�Һ���˶�
        if(score_all >= 30)
        {
            dSetSpriteLinearVelocityX( "drop_1", dRandomRange( 1, 5 ) );
            dSetSpriteLinearVelocityX( "drop_2", dRandomRange( 1, 5 ) );
            dSetSpriteLinearVelocityX( "drop_3", dRandomRange( 1, 5 ) );
            dSetSpriteLinearVelocityX( "drop_4", dRandomRange( 1, 5 ) );
            dSetSpriteLinearVelocityX( "drop_5", dRandomRange( 1, 5 ) );
            dSetSpriteLinearVelocityX( "drop_6", dRandomRange( 1, 5 ) );
            dSetSpriteLinearVelocityX( "drop_7", dRandomRange( 1, 5 ) );
        }
        //��ȡ��Һλ��
        float v_fPosX_1=dGetSpritePositionX( "drop_1" );
        float v_fPosX_2=dGetSpritePositionX( "drop_2" );
        float v_fPosX_3=dGetSpritePositionX( "drop_3" );
        float v_fPosX_4=dGetSpritePositionX( "drop_4" );
        float v_fPosX_5=dGetSpritePositionX( "drop_5" );
        float v_fPosX_6=dGetSpritePositionX( "drop_6" );
        float v_fPosX_7=dGetSpritePositionX( "drop_7" );
        //���ö�Һ������ĽӴ�
        if(fabs(v_fPosX_1-w_fPosX_1)<=3)
            dDeleteSprite("drop_1");
        if(fabs(v_fPosX_1-w_fPosX_2)<=3)
            dDeleteSprite("drop_1");
        if(fabs(v_fPosX_1-w_fPosX_3)<=3)
            dDeleteSprite("drop_1");
        if(fabs(v_fPosX_2-w_fPosX_1)<=3)
            dDeleteSprite("drop_1");
        if(fabs(v_fPosX_2-w_fPosX_2)<=3)
            dDeleteSprite("drop_1");
        if(fabs(v_fPosX_2-w_fPosX_3)<=3)
            dDeleteSprite("drop_1");
        if(fabs(v_fPosX_3-w_fPosX_1)<=3)
            dDeleteSprite("drop_1");
    }


}
//==============================================================================
//
// ������Ϸ����
void GameEnd()
{
    if(shuju == 2)
    {
        dStopAllSound();
        if(game_flag_2 == 1)
        {
            dLoadMap( "third.t2d" );
            dPlaySound("Lifting.ogg", 1, 1 );
            shuju++;
        }

        if(game_flag_2 == 2)
        {
            dLoadMap( "game_over_2.t2d" );
            dPlaySound("gameover.ogg", 1, 1 );
        }
    }
    if(shuju == 3)
    {
        //dPlaySound("sfl.ogg", 0, 0 );
        dStopAllSound();
        if(game_flag == 1)
        {
            dLoadMap( "game_end.t2d" );
            dPlaySound("Lifting.ogg", 0, 1 );
        }

        if(game_flag == 2)
        {
            dLoadMap( "third_1.t2d" );
            //dLoadMap( "third_1.t2d" );
            dPlaySound("gameover.ogg", 1, 1 );

        }

        //dLoadMap( "third_1.t2d" );
    }

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
    if(shuju == 0&&g_iGameState>=0&&g_iGameState<=2)
    {
        if(iMouseType==0)
            num_0++;
        if(num_0==1)
            g_iGameState		=	1;

        int a =  dIsPointInSprite( "game_setting", fMouseX, fMouseY );
        int b =  dIsPointInSprite( "next_back", fMouseX, fMouseY );
        int c =  dIsPointInSprite( "game_rule", fMouseX, fMouseY );
        int d =  dIsPointInSprite( "next_method", fMouseX, fMouseY );
        int g =  dIsPointInSprite( "start_button", fMouseX, fMouseY );

        if(a==1)
        {
            dSetSpriteVisible("back",1);
            dSetSpriteVisible("next_back",1);
        }
        if(b==1)
        {
            dSetSpriteVisible("back",0);
            dSetSpriteVisible("next_back",0);
        }
        if(c==1)
        {
            dSetSpriteVisible("method",1);
            dSetSpriteVisible("next_method",1);
        }
        if(d==1)
        {
            dSetSpriteVisible("method",0);
            dSetSpriteVisible("next_method",0);
        }
        if(g==1)
        {
            dLoadMap("first.t2d");//��ת����һ�����ڳ���
            //dStopAllSound();
            shuju++;
        }


        if(iMouseType==0)
        {
            int f = dIsPointInSprite( "music_close", fMouseX, fMouseY );
            if(f==1)
            {
                dSetSpriteVisible("music_open",1);
                dSetSpriteVisible("music_close",0);
            }
        }
    }
    if(shuju == 1&&g_iGameState>=0&&g_iGameState<=2)
    {
        dSpriteMoveTo("Leadman",fMouseX,fMouseY,5,1);
        int h =  dIsPointInSprite( "kouzhao", fMouseX, fMouseY );
        if(h==1)
        {
            dLoadMap("new.t2d");//��ת���ڶ������ڳ���
            //dStopAllSound();
            shuju++;
        }
    }
    if(shuju == 3)
    {
        if(iMouseType==0)
            num++;
        if(num==1)
        {
            dPlaySound("sfl.ogg",0,1);
            dSetSpriteLinearVelocity( "miwu_1", -10, -10 );
            dSetSpriteLinearVelocity( "miwu_2", 10, -10 );
            dSetSpriteLinearVelocity( "miwu_3", -10, 10 );
            dSetSpriteLinearVelocity( "miwu_4", 10, 10 );
            dSetSpriteVisible("wu_1",1);
            dSetSpriteVisible("wu_2",1);
            dSetSpriteVisible("wu_3",1);
            dSetSpriteLifeTime( "wu_1", 3 );
            dSetSpriteLifeTime( "wu_2", 3 );
            dSetSpriteLifeTime( "wu_3", 3 );
        }
        if(num==2)
        {
            dSetSpriteVisible("hosptial",0);
            dSetSpriteVisible("gqjs",0);
            g_iGameState	=	1;
        }


        if(iMouseType==0&&num%2==1)
        {
            int a = dIsPointInSprite( "music_open", fMouseX, fMouseY );
            if(a==1)
            {
                dSetSpriteVisible("music_open",0);
                dSetSpriteVisible("music_close",1);
                dStopAllSound();
            }
        }
        if(iMouseType==0&&num%2==0)
        {
            int c = dIsPointInSprite( "music_close", fMouseX, fMouseY );
            if(c == 1)
            {
                dSetSpriteVisible("music_open",1);
                dSetSpriteVisible("music_close",0);
                dPlaySound("sfl.ogg", 1, 1 );
            }
        }

        if(iMouseType==0)
        {
            int f = dIsPointInSprite( "add_1", fMouseX, fMouseY );
            if(f==1)
            {
                time_left+=5;
                dDeleteSprite("add_1");
            }
            int m = dIsPointInSprite( "add_2", fMouseX, fMouseY );
            if(m==1)
            {
                time_left+=5;
                dDeleteSprite("add_2");
            }
            int n = dIsPointInSprite( "add_3", fMouseX, fMouseY );
            if(n==1)
            {
                time_left+=5;
                dDeleteSprite("add_3");
            }
        }
    }

}
//==========================================================================
//
// ��굯��
// ���� iMouseType����갴��ֵ���� enum MouseTypes ����
// ���� fMouseX, fMouseY��Ϊ��굱ǰ����
void OnMouseUp( const int iMouseType, const float fMouseX, const float fMouseY )
{
    if(shuju == 1)
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


}
//==========================================================================
//
// ���̰���
// ���� iKey�������µļ���ֵ�� enum KeyCodes �궨��
// ���� iAltPress, iShiftPress��iCtrlPress�������ϵĹ��ܼ�Alt��Ctrl��Shift��ǰ�Ƿ�Ҳ���ڰ���״̬(0δ���£�1����)
void OnKeyDown( const int iKey, const bool bAltPress, const bool bShiftPress, const bool bCtrlPress )
{
    if(shuju == 1)
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
        {
            dCloneSprite("story","copy1");
            dSetSpritePosition("copy1",0,0);
        }
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
            }
        }
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
            }
        }
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
            {
                printf("2  ");
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
            }
        }
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
            }
        }
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
            }
        }
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
            {
                printf("2  ");
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
            }
        }
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
    if(shuju == 2)
    {
        //circle=0;
        if(iKey==KEY_SPACE)
            circle++;
        if(circle==1)
            g_iGameState=1;
        if(circle==2)
            dDeleteSprite("jieshao");
        if(g_iGameState	== 2)
        {
            {
                switch(iKey)
                {
                case KEY_W:
                    g_fSpeedTop = -10.f;
                    break;
                case KEY_A:
                    g_fSpeedLeft = -15.f;
                    break;
                case KEY_S:
                    g_fSpeedBottom = 10.f;
                    break;
                case KEY_D:
                    g_fSpeedRight = 15.f;
                    break;
                default:
                    break;
                }
                dSetSpriteLinearVelocity("man", g_fSpeedLeft + g_fSpeedRight, g_fSpeedTop + g_fSpeedBottom);
                if((g_fSpeedLeft + g_fSpeedRight) > 0.f)
                    dSetSpriteFlipX("man", 0);
                else if((g_fSpeedLeft + g_fSpeedRight) < 0.f)
                    dSetSpriteFlipX("man", 1);
            }
        }
    }
    if(shuju == 3)
    {
        //���̿��ƻ�����ƶ�
        if(g_iGameState	== 2)
        {
            {
                switch(iKey)
                {
                case KEY_W:
                    g_fSpeedTop_A = -10.f;
                    break;
                case KEY_A:
                    g_fSpeedLeft_A = -15.f;
                    break;
                case KEY_S:
                    g_fSpeedBottom_A = 10.f;
                    break;
                case KEY_D:
                    g_fSpeedRight_A = 15.f;
                    break;
                default:
                    break;
                }
                dSetSpriteLinearVelocity("A_man", g_fSpeedLeft_A + g_fSpeedRight_A, g_fSpeedTop_A + g_fSpeedBottom_A);
                if((g_fSpeedLeft_A + g_fSpeedRight_A) > 0.f)
                    dSetSpriteFlipX("A_man", 0);
                else if((g_fSpeedLeft_A + g_fSpeedRight_A) < 0.f)
                    dSetSpriteFlipX("A_man", 1);
            }
            {
                switch(iKey)
                {
                case KEY_UP:
                    g_fSpeedTop_B = -10.f;
                    break;
                case KEY_LEFT:
                    g_fSpeedLeft_B = -15.f;
                    break;
                case KEY_DOWN:
                    g_fSpeedBottom_B = 10.f;
                    break;
                case KEY_RIGHT:
                    g_fSpeedRight_B = 15.f;
                    break;
                default:
                    break;
                }
                dSetSpriteLinearVelocity("B_man", g_fSpeedLeft_B + g_fSpeedRight_B, g_fSpeedTop_B + g_fSpeedBottom_B);
                if((g_fSpeedLeft_B + g_fSpeedRight_B) > 0.f)
                    dSetSpriteFlipX("B_man", 0);
                else if((g_fSpeedLeft_B + g_fSpeedRight_B) < 0.f)
                    dSetSpriteFlipX("B_man", 1);
            }
        }

        //���̿���A��̹�˵ķ������
        if(g_iGameState	== 2)
        {
            if(iKey==KEY_SPACE)
            {
                if(time_A==1)
                {
                    dSetSpriteVisible("paowu_1",1);
                    wu_state_1=1;
                }
                if(time_A==2)
                {
                    dSetSpriteVisible("paowu_2",1);
                    wu_state_2=1;
                }
                if(time_A==3)
                {
                    dSetSpriteVisible("paowu_3",1);
                    wu_state_3=1;
                }
            }
        }
        //���̿���B��̹�˷����ڵ������
        if(g_iGameState	== 2)
        {
            if(iKey==KEY_L)
            {
                if(time_B==1)
                {
                    dSetSpriteVisible("bomb_1",1);
                }
                if(time_B==2)
                {
                    dSetSpriteVisible("bomb_2",1);
                }
                if(time_B==3)
                {
                    dSetSpriteVisible("bomb_3",1);
                }
            }
        }
    }

}


//==========================================================================
//
// ���̵���
// ���� iKey������ļ���ֵ�� enum KeyCodes �궨��
void OnKeyUp( const int iKey )
{
    if(shuju == 2)
    {
        if(g_iGameState	==	2)
        {
            {
                switch(iKey)
                {
                case KEY_W:
                    g_fSpeedTop = 0.f;
                    break;
                case KEY_A:
                    g_fSpeedLeft = 0.f;
                    break;
                case KEY_S:
                    g_fSpeedBottom = 0.f;
                    break;
                case KEY_D:
                    g_fSpeedRight = 0.f;
                    break;
                }
                dSetSpriteLinearVelocity("man", g_fSpeedLeft + g_fSpeedRight, g_fSpeedTop + g_fSpeedBottom);
                if((g_fSpeedLeft + g_fSpeedRight) > 0.f)
                    dSetSpriteFlipX("man", 0);
                else if((g_fSpeedLeft + g_fSpeedRight) < 0.f)
                    dSetSpriteFlipX("man", 1);
            }
        }
    }
    if(shuju == 3)
    {
        //���̿��ƻ�����ƶ�
        if(g_iGameState	==	2)
        {
            {
                switch(iKey)
                {
                case KEY_W:
                    g_fSpeedTop_A = 0.f;
                    break;
                case KEY_A:
                    g_fSpeedLeft_A = 0.f;
                    break;
                case KEY_S:
                    g_fSpeedBottom_A = 0.f;
                    break;
                case KEY_D:
                    g_fSpeedRight_A = 0.f;
                    break;
                }
                dSetSpriteLinearVelocity("A_man", g_fSpeedLeft_A + g_fSpeedRight_A, g_fSpeedTop_A + g_fSpeedBottom_A);
                if((g_fSpeedLeft_A + g_fSpeedRight_A) > 0.f)
                    dSetSpriteFlipX("A_man", 0);
                else if((g_fSpeedLeft_A + g_fSpeedRight_A) < 0.f)
                    dSetSpriteFlipX("A_man", 1);
            }
            {
                switch(iKey)
                {
                case KEY_UP:
                    g_fSpeedTop_B = 0.f;
                    break;
                case KEY_LEFT:
                    g_fSpeedLeft_B = 0.f;
                    break;
                case KEY_DOWN:
                    g_fSpeedBottom_B = 0.f;
                    break;
                case KEY_RIGHT:
                    g_fSpeedRight_B = 0.f;
                    break;
                }
                dSetSpriteLinearVelocity("B_man", g_fSpeedLeft_B + g_fSpeedRight_B, g_fSpeedTop_B + g_fSpeedBottom_B);
                if((g_fSpeedLeft_B + g_fSpeedRight_B) > 0.f)
                    dSetSpriteFlipX("B_man", 0);
                else if((g_fSpeedLeft_B + g_fSpeedRight_B) < 0.f)
                    dSetSpriteFlipX("B_man", 1);
            }
        }
        //���̿���A��̹�˵ķ������
        if(g_iGameState	== 2)
        {
            if(iKey==KEY_SPACE)
            {
                if(time_A==1)
                {
                    //dSetSpriteVisible("paowu_1",0);
                    //wu_state_1=0;
                    dSetSpriteVisible("paowu_1",0);
                    dCloneSprite( "paowu_1", "paowu_01" );
                    dSetSpriteVisible("paowu_01",1);
                    dSetSpritePosition( "paowu_01",  fPosX_1,  fPosY_1 );
                    dSetSpriteConstantForce("paowu_01", -5, 2, 1 );
                    //��ȡ����λ��
                    w_fPosX_1=dGetSpritePositionX( "paowu_1" );
                }
                if(time_A==2)
                {
                    //dSetSpriteVisible("paowu_2",0);
                    //wu_state_2=0;
                    dSetSpriteVisible("paowu_2",0);
                    dCloneSprite( "paowu_2", "paowu_02" );
                    dSetSpriteVisible("paowu_02",1);
                    dSetSpritePosition( "paowu_02",  fPosX_2,  fPosY_2 );
                    dSetSpriteConstantForce("paowu_02", -5, 2, 1 );
                    w_fPosX_2=dGetSpritePositionX( "paowu_2" );
                }
                if(time_A==3)
                {
                    //dSetSpriteVisible("paowu_3",0);
                    //wu_state_3=0;
                    dSetSpriteVisible("paowu_3",0);
                    dCloneSprite( "paowu_3", "paowu_03" );
                    dSetSpriteVisible("paowu_03",1);
                    dSetSpritePosition( "paowu_03",  fPosX_3,  fPosY_3 );
                    dSetSpriteConstantForce("paowu_03", -5, 2, 1 );
                    w_fPosX_3=dGetSpritePositionX( "paowu_3" );
                }
            }
            time_A=0;//����Ҫ��Ҫ��time_A���س�ʼֵ��
        }
        //���̿���B��̹�˷����ڵ������
        if(g_iGameState	== 2)
        {
            if(iKey==KEY_L)
            {
                if(time_B==1)
                {
                    dSetSpriteVisible("bomb_1",0);
                    dCloneSprite( "bomb_1", "bomb_01" );
                    dSetSpriteVisible("bomb_01",1);
                    dSetSpritePosition( "bomb_01",  fPosX_1,  fPosY_1 );
                    dSetSpriteConstantForce("bomb_01", -5, 2, 1 );
                }
                if(time_B==2)
                {
                    dSetSpriteVisible("bomb_2",0);
                    dCloneSprite( "bomb_2", "bomb_02" );
                    dSetSpriteVisible("bomb_02",1);
                    dSetSpritePosition( "bomb_02",  fPosX_2,  fPosY_2 );
                    dSetSpriteConstantForce("bomb_02", -5, 2, 1 );
                }
                if(time_B==3)
                {
                    dSetSpriteVisible("bomb_3",0);
                    dCloneSprite( "bomb_3", "bomb_03" );
                    dSetSpriteVisible("bomb_03",1);
                    dSetSpritePosition( "bomb_03",  fPosX_3,  fPosY_3 );
                    dSetSpriteConstantForce("bomb_03", -5, 2, 1 );
                }
            }
            time_B=0;//����Ҫ��Ҫ��time_A���س�ʼֵ��
        }
    }

}
//===========================================================================
//
// �����뾫����ײ
// ���� szSrcName��������ײ�ľ�������
// ���� szTarName������ײ�ľ�������
void OnSpriteColSprite( const char *szSrcName, const char *szTarName )
{
    if(shuju == 1&&g_iGameState>=0&&g_iGameState<=2)
    {
        float fx,fy;

        if(g_iGameState==5)
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
        }
    }
    if(shuju == 2)
    {
        if(strcmp(szSrcName, "man")==0&&strstr(szTarName, "wall")!=NULL)
        {
            float fVelX = -dGetSpriteLinearVelocityX("man");
            float fVelY = -dGetSpriteLinearVelocityY( "man" );
            dSetSpriteLinearVelocity("man", fVelX, fVelY);
        }
        if(strcmp(szSrcName, "man")==0&&strstr(szTarName, "heart")!=NULL)
        {
            dSpriteMoveTo( szTarName, fPosX, fPosY, 10, 1 );
            dSetSpriteScale( szTarName, 0.7 );
            dPlaySound("BLIP.wav",0,1);
            n++;
        }
        if(strcmp(szSrcName, "man")==0&&strcmp(szTarName, "end")==0)
        {
            flag=1;
        }
    }
    if(shuju == 3)
    {
        //���û���˲��ܴ���Χǽ
        if(strcmp(szSrcName, "A_man")==0&&strstr(szTarName, "barrier")!=NULL)
        {
            float fVelX = -dGetSpriteLinearVelocityX("A_man");
            float fVelY = -dGetSpriteLinearVelocityY( "A_man" );
            dSetSpriteLinearVelocity("A_man", fVelX, fVelY);
        }
        if(strcmp(szSrcName, "B_man")==0&&strstr(szTarName, "barrier")!=NULL)
        {
            float fVelX = -dGetSpriteLinearVelocityX("B_man");
            float fVelY = -dGetSpriteLinearVelocityY( "B_man" );
            dSetSpriteLinearVelocity("B_man", fVelX, fVelY);
        }

        //���û����A��̹�˵���ײ��������
        if(strcmp(szSrcName, "A_man")==0&&strstr(szTarName, "tank")!=NULL)
        {
            if(strcmp(szTarName, "tank_1")==0)
                time_A=1;
            else if(strcmp(szTarName, "tank_2")==0)
                time_A=2;
            else if(strcmp(szTarName, "tank_3")==0)
                time_A=3;
        }
        //���û����B��̹�˵���ײ�����ڵ�
        if(strcmp(szSrcName, "B_man")==0&&strstr(szTarName, "tank")!=NULL)
        {
            if(strcmp(szTarName, "tank_1")==0)
                time_B=1;
            if(strcmp(szTarName, "tank_2")==0)
                time_B=2;
            if(strcmp(szTarName, "tank_3")==0)
                time_B=3;
        }
        //����С������Χǽ����ײ
        if(strstr(szSrcName, "Small_Virus")!=NULL&&strstr(szTarName, "barrier")!=NULL)
        {
            dSetSpriteLinearVelocity( szSrcName, 0, 0 );
        }
        //���ô󲡶���Χǽ����ײ
        if(strstr(szSrcName, "Big")!=NULL&&strstr(szTarName, "barrier")!=NULL)
        {
            dSetSpriteLinearVelocity( szSrcName, 0, 0 );
            dSetSpriteScale( szSrcName, 0.5 );
        }
        //���ö�Һ��Χǽ����ײ
        if(strstr(szSrcName, "drop")!=NULL&&strstr(szTarName, "barrier")!=NULL)
        {
            dSetSpriteLinearVelocity( szSrcName, 0, 0 );
            number++;
        }

        //�����ڵ���С�����Ӵ�С������ʧ
        if(strstr(szSrcName, "Small_Virus")!=NULL&&strstr(szTarName, "bomb")!=NULL)
        {
            dDeleteSprite( szSrcName );
            float   b_PositionX  =  dGetSpritePositionX( szSrcName );
            float   b_PositionY  =  dGetSpritePositionY( szSrcName );
            dCloneSprite( "explosion_0", "explosion_1" );
            dSetSpritePosition( "explosion_1", b_PositionX, b_PositionY );
            dDeleteSprite(szTarName);
            dSetSpriteLifeTime( "explosion_1", 0.5);
            dPlaySound("xiaopao.ogg", 0, 1 );
            score_small+=5;
        }
        //���ø��ƺ��С�������ڵ�����ײ
        if(strstr(szSrcName, "s_virus")!=NULL&&strstr(szTarName, "bomb")!=NULL)
        {
            dDeleteSprite( szSrcName );
            float   b_PositionX  =  dGetSpritePositionX( szSrcName );
            float   b_PositionY  =  dGetSpritePositionY( szSrcName );
            dCloneSprite( "explosion_0", "explosion_1" );
            dSetSpritePosition( "explosion_1", b_PositionX, b_PositionY );
            dDeleteSprite(szTarName);
            dSetSpriteLifeTime( "explosion_1", 0.5);
            dPlaySound("xiaopao.ogg", 0, 1 );
            score_small+=5;
        }
        //�����ڵ���󲡶��ĽӴ�
        if(strstr(szSrcName, "Big")!=NULL&&strstr(szTarName, "bomb")!=NULL)
        {
            //dSetSpriteScale( szSrcName, 0.5 );
            dDeleteSprite( szSrcName );
            float   b_PositionX  =  dGetSpritePositionX( szSrcName );
            float   b_PositionY  =  dGetSpritePositionY( szSrcName );
            dCloneSprite( "explosion_00", "explosion_11" );
            dSetSpritePosition( "explosion_11", b_PositionX, b_PositionY );
            dDeleteSprite(szTarName);
            dSetSpriteLifeTime( "explosion_11", 0.5);
            dPlaySound("kaipao.ogg", 0, 1 );
            score_big+=10;
        }

        if(strstr(szSrcName, "virus")!=NULL&&strstr(szTarName, "paowu")!=NULL)
        {
            dSetSpriteScale( szSrcName, 0.5 );
        }

        //���ø��ƺ�Ĵ󲡶����ڵ���ײ
        if(strstr(szSrcName, "b_virus")!=NULL&&strstr(szTarName, "bomb")!=NULL)
        {
            dDeleteSprite( szSrcName );
            float   b_PositionX  =  dGetSpritePositionX( szSrcName );
            float   b_PositionY  =  dGetSpritePositionY( szSrcName );
            dCloneSprite( "explosion_00", "explosion_11" );
            dSetSpritePosition( "explosion_11", b_PositionX, b_PositionY );
            dDeleteSprite(szTarName);
            dSetSpriteLifeTime( "explosion_11", 0.5);
            dPlaySound("kaipao.ogg", 0, 1 );
            score_big+=10;
        }
        //���ø��ƺ��С������Χǽ����ײ
        if(strstr(szSrcName, "s_virus")!=NULL&&strstr(szTarName, "barrier")!=NULL)
        {
            dSetSpriteLinearVelocity( szSrcName, 0, 0 );

        }
        //���ø��ƺ�Ĵ󲡶���Χǽ����ײ
        if(strstr(szSrcName, "b_virus")!=NULL&&strstr(szTarName, "barrier")!=NULL)
        {
            dSetSpriteLinearVelocity( szSrcName, 0, 0 );

        }

        if(strcmp(szSrcName, "A_man")==0&&strstr(szTarName, "trigger")!=NULL)
        {
            if(strcmp(szTarName, "trigger_1")==0)
            {
                dSetSpriteVisible("add_1",1);
                dSetSpriteLifeTime("add_1",3);
            }
            if(strcmp(szTarName, "trigger_2")==0)
            {
                dSetSpriteVisible("add_3",1);
                dSetSpriteLifeTime("add_3",3);
            }
            if(strcmp(szTarName, "trigger_3")==0)
            {
                dSetSpriteVisible("add_2",1);
                dSetSpriteLifeTime("add_2",3);
            }
        }
    }

}

//===========================================================================
//
// ����������߽���ײ
// ���� szName����ײ���߽�ľ�������
// ���� iColSide����ײ���ı߽� 0 ��ߣ�1 �ұߣ�2 �ϱߣ�3 �±�
void OnSpriteColWorldLimit( const char *szName, const int iColSide )
{
    if(shuju == 2)
    {
        //iColSide����ײ���ı߽� 0 ��ߣ�1 �ұߣ�2 �ϱߣ�3 �±�
        //���û���˲���Խ������߽�
        if(strcmp(szName, "man")==0)
        {
            if(iColSide == 0) //���
            {
                //dSetSpriteFlipX("man", 1);
                dSetSpriteLinearVelocity("man", 0, 0);
            }
            else if(iColSide == 1)  // �ұ�
            {
                //dSetSpriteFlipX("man", 0);
                dSetSpriteLinearVelocity("man", 0, 0);
            }
            else if(iColSide == 2)   // �ϱ�
            {
                //dSetSpriteFlipX("man", 1);
                dSetSpriteLinearVelocity("man", 0, 0);
            }
            else if(iColSide == 3)  //�±�
            {
                //dSetSpriteFlipX("man", 0);
                dSetSpriteLinearVelocity("man", 0, 0);
            }
        }
    }
    if(shuju == 3)
    {
        //iColSide����ײ���ı߽� 0 ��ߣ�1 �ұߣ�2 �ϱߣ�3 �±�
        //���û���˲���Խ������߽�
        if(strcmp(szName, "A_man")==0)
        {
            if(iColSide == 1||iColSide == 2)  // �ұ�
            {
                dSetSpriteFlipX("A_man", 1);
                dSetSpriteLinearVelocity("A_man", -10, 10);
            }
            else if(iColSide == 0||iColSide == 3)   // ���
            {
                dSetSpriteFlipX("A_man", 0);
                dSetSpriteLinearVelocity("A_man", 10, -10);
            }
        }
        if(strcmp(szName, "B_man")==0)
        {
            if(iColSide == 1||iColSide == 2)  // �ұ�
            {
                dSetSpriteFlipX("B_man", 1);
                dSetSpriteLinearVelocity("B_man", -10, 10);
            }
            else if(iColSide == 0||iColSide == 3)   // ���
            {
                dSetSpriteFlipX("B_man", 0);
                dSetSpriteLinearVelocity("B_man", 10, -10);
            }
        }

    }
}
