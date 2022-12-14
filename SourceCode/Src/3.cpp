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
////////////////////////////////////////////////////////////////////////////////
//
//
int			g_iGameState		=	0;		// ��Ϸ״̬��0 -- ��Ϸ�����ȴ���ʼ״̬��1 -- ���¿ո����ʼ����ʼ����Ϸ��2 -- ��Ϸ������

//���������������ȫ�ֱ���num=0
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
//
void		GameInit();
void		GameRun( float fDeltaTime );
void		GameEnd();
void        TimeLimit( float fDeltaTime );
int 	    dIsPointInSprite();
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
        if( game_flag == 0 )
        {

            TimeLimit( fDeltaTime );
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
//dGetTimeDelta();
void    TimeLimit( float fDeltaTime )
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
//==============================================================================
//
// ÿ����Ϸ������
void GameRun( float fDeltaTime )
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
//==============================================================================
//
// ������Ϸ����
void GameEnd()
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
//==========================================================================
//
// ��굯��
// ���� iMouseType����갴��ֵ���� enum MouseTypes ����
// ���� fMouseX, fMouseY��Ϊ��굱ǰ����
void OnMouseUp( const int iMouseType, const float fMouseX, const float fMouseY )
{

}
//==========================================================================
//
// ���̰���
// ���� iKey�������µļ���ֵ�� enum KeyCodes �궨��
// ���� iAltPress, iShiftPress��iCtrlPress�������ϵĹ��ܼ�Alt��Ctrl��Shift��ǰ�Ƿ�Ҳ���ڰ���״̬(0δ���£�1����)
void OnKeyDown( const int iKey, const bool bAltPress, const bool bShiftPress, const bool bCtrlPress )
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
//==========================================================================
//
// ���̵���
// ���� iKey������ļ���ֵ�� enum KeyCodes �궨��
void OnKeyUp( const int iKey )
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
//===========================================================================
//
// �����뾫����ײ
// ���� szSrcName��������ײ�ľ�������
// ���� szTarName������ײ�ľ�������
void OnSpriteColSprite( const char *szSrcName, const char *szTarName )
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
//===========================================================================
//
// ����������߽���ײ
// ���� szName����ײ���߽�ľ�������
// ���� iColSide����ײ���ı߽� 0 ��ߣ�1 �ұߣ�2 �ϱߣ�3 �±�
void OnSpriteColWorldLimit( const char *szName, const int iColSide )
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
