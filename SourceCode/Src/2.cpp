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
int			g_iGameState		=	0;		// 游戏状态，0 -- 游戏结束等待开始状态；1 -- 按下空格键开始，初始化游戏；2 -- 游戏进行中

float		g_fSpeedLeft		=	0.f;  	// 左方向速度
float		g_fSpeedRight	=	0.f;  	// 右
float		g_fSpeedTop		    =	0.f;  	// 上
float		g_fSpeedBottom	    =	0.f;  	// 下
//获取世界边界的全局变量
float       g_fScreenLeft  ;
float       g_fScreenRight   ;
float       g_fScreenTop       ;
float       g_fScreenBottom    ;

float        fPosX;
float        fPosY;

int         circle=0;
int         n=0;
int         flag=0;
//定义游戏结束标志的全局变量
int         game_flag_2;

//定义时间限制
float         time_left=60;
//
void		GameInit();
void		GameRun( float fDeltaTime );
void		GameEnd();
void        TimeLimit( float fDeltaTime );
//==============================================================================
//
// 大体的程序流程为：GameMainLoop函数为主循环函数，在引擎每帧刷新屏幕图像之后，都会被调用一次。


//==============================================================================
//
// 游戏主循环，此函数将被不停的调用，引擎每刷新一次屏幕，此函数即被调用一次
// 用以处理游戏的开始、进行中、结束等各种状态.
// 函数参数fDeltaTime : 上次调用本函数到此次调用本函数的时间间隔，单位：秒
void GameMainLoop( float	fDeltaTime )
{
    switch( g_iGameState )
    {
    // 初始化游戏，清空上一局相关数据
    case 1:
    {
        GameInit();
        g_iGameState	=	2; // 初始化之后，将游戏状态设置为进行中
    }
    break;

    // 游戏进行中，处理各种游戏逻辑
    case 2:
    {
        // TODO 修改此处游戏循环条件，完成正确游戏逻辑
        if( game_flag_2 == 0 )
        {
            TimeLimit( fDeltaTime );
            GameRun( fDeltaTime );
        }
        else
        {
            // 游戏结束。调用游戏结算函数，并把游戏状态修改为结束状态
            g_iGameState	=	0;
            GameEnd();
        }
    }
    break;

    // 游戏结束/等待按空格键开始
    case 0:
    default:
        break;
    };
}

//==============================================================================
//
// 每局开始前进行初始化，清空上一局相关数据

void    TimeLimit( float fDeltaTime )
{

    time_left -= fDeltaTime;
    dSetTextValue( "time_left", time_left );

    if(n >= 5 && flag==1 )
    {
        game_flag_2   =   1;
    }
    else if(time_left <= 0 && ( n<5 || flag==0 ))
    {
        game_flag_2   =   2;
    }

}

void GameInit()
{
    game_flag_2 = 0;

    g_fScreenLeft       =   dGetScreenLeft();
    g_fScreenRight      =   dGetScreenRight();
    g_fScreenTop        =   dGetScreenTop();
    g_fScreenBottom     =   dGetScreenBottom();
    dSetSpriteWorldLimit("man", WORLD_LIMIT_NULL, g_fScreenLeft, g_fScreenTop, g_fScreenRight, g_fScreenBottom);

    dPlaySound("Lifting.ogg",1,1);
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
//==============================================================================
//
// 每局游戏进行中
void GameRun( float fDeltaTime )
{

}
//==============================================================================
//
// 本局游戏结束
void GameEnd()
{
    dStopAllSound();
    if(game_flag_2 == 1)
    {
        dLoadMap( "third.t2d" );
        dPlaySound("Lifting.ogg", 1, 1 );
    }

    if(game_flag_2 == 2)
    {
        dLoadMap( "game_over_2.t2d" );
        dPlaySound("gameover.ogg", 1, 1 );
    }
}
//==========================================================================
//
// 鼠标移动
// 参数 fMouseX, fMouseY：为鼠标当前坐标
void OnMouseMove( const float fMouseX, const float fMouseY )
{

}
//==========================================================================
//
// 鼠标点击
// 参数 iMouseType：鼠标按键值，见 enum MouseTypes 定义
// 参数 fMouseX, fMouseY：为鼠标当前坐标
void OnMouseClick( const int iMouseType, const float fMouseX, const float fMouseY )
{

}
//==========================================================================
//
// 鼠标弹起
// 参数 iMouseType：鼠标按键值，见 enum MouseTypes 定义
// 参数 fMouseX, fMouseY：为鼠标当前坐标
void OnMouseUp( const int iMouseType, const float fMouseX, const float fMouseY )
{

}
//==========================================================================
//
// 键盘按下
// 参数 iKey：被按下的键，值见 enum KeyCodes 宏定义
// 参数 iAltPress, iShiftPress，iCtrlPress：键盘上的功能键Alt，Ctrl，Shift当前是否也处于按下状态(0未按下，1按下)
void OnKeyDown( const int iKey, const bool bAltPress, const bool bShiftPress, const bool bCtrlPress )
{
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
//==========================================================================
//
// 键盘弹起
// 参数 iKey：弹起的键，值见 enum KeyCodes 宏定义
void OnKeyUp( const int iKey )
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
//===========================================================================
//
// 精灵与精灵碰撞
// 参数 szSrcName：发起碰撞的精灵名字
// 参数 szTarName：被碰撞的精灵名字
void OnSpriteColSprite( const char *szSrcName, const char *szTarName )
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
//===========================================================================
//
// 精灵与世界边界碰撞
// 参数 szName：碰撞到边界的精灵名字
// 参数 iColSide：碰撞到的边界 0 左边，1 右边，2 上边，3 下边
void OnSpriteColWorldLimit( const char *szName, const int iColSide )
{
     //iColSide：碰撞到的边界 0 左边，1 右边，2 上边，3 下边
    //设置火柴人不能越过世界边界
    if(strcmp(szName, "man")==0)
    {
        if(iColSide == 0) //左边
        {
            //dSetSpriteFlipX("man", 1);
            dSetSpriteLinearVelocity("man", 0, 0);
        }
        else if(iColSide == 1)  // 右边
        {
            //dSetSpriteFlipX("man", 0);
            dSetSpriteLinearVelocity("man", 0, 0);
        }
        else if(iColSide == 2)   // 上边
        {
            //dSetSpriteFlipX("man", 1);
            dSetSpriteLinearVelocity("man", 0, 0);
        }
        else if(iColSide == 3)  //下边
        {
            //dSetSpriteFlipX("man", 0);
            dSetSpriteLinearVelocity("man", 0, 0);
        }
    }
}
