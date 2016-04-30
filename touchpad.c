#include <os.h>
#include "touchpad.h"

#ifdef TOUCHPAD_SUPPORT
touchpad_info_t* tpinfo;
#endif

void initTP()//��ʼ��TP
{        
#ifdef TOUCHPAD_SUPPORT
        tpinfo = touchpad_getinfo();
        tpreport = (touchpad_report_t*) malloc(sizeof(touchpad_report_t));
        memset(tpreport,0,sizeof(touchpad_report_t));
#endif
}

void endTP()//�ͷ�
{
#ifdef TOUCHPAD_SUPPORT
        free(tpreport);
#endif
}

void readTP()//��ȡTP״̬
{
#ifdef TOUCHPAD_SUPPORT
        touchpad_scan(tpreport);
#endif
}

void readFullTP()//������ʱ���ٶ�ȡTP״̬
{
#ifdef TOUCHPAD_SUPPORT
        sleep(TOUCHPAD_DELAY); // lets the time to compute velocity
        readTP();
#endif
}

int getX_Velocity()//��ȡX���������
{
#ifdef TOUCHPAD_SUPPORT
        if(!is_touchpad) return 0;
        if(!tpreport->contact) return 0;
        int t = tpreport->x_velocity;
        if(t<=127) return t;
        return t-256;
#else
        return 0;
#endif
}

int getY_Velocity()//��ȡY���������
{
#ifdef TOUCHPAD_SUPPORT
        if(!is_touchpad) return 0;
        if(!tpreport->contact) return 0;
        int t = tpreport->y_velocity;
        if(t<=127) return t;
        return t-256;
#else
        return 0;
#endif
}

int getX()//��ȡX�ľ�������
{
#ifdef TOUCHPAD_SUPPORT
        if(!is_touchpad) return 0;
        if(!tpreport->contact) return 0;
        int t = tpreport->x;
        return t;
#else
        return 0;
#endif
}

int getY()//��ȡY�ľ�������
{
#ifdef TOUCHPAD_SUPPORT
        if(!is_touchpad) return 0;
        if(!tpreport->contact) return 0;
        int t = tpreport->y;
        return t;
#else
        return 0;
#endif
}

/* 8
  456
   2
*/
int getTouchedZone5()//��TouchPad�ֳ�5�����򣬶�ȡֵ
{
#ifdef TOUCHPAD_SUPPORT
        if(!is_touchpad) return 0;
        if(!tpreport->contact) return 0;
        if(tpreport->x>tpinfo->width/3 && tpreport->x<2*tpinfo->width/3 && tpreport->y>tpinfo->height/3 && tpreport->y<2*tpinfo->height/3)
                return 5;
        float m = (float)tpinfo->height/tpinfo->width;
        float ac,ad;
        if(tpreport->x==0)
                if(tpreport->y==0)        ac=m;
                else                        ac=tpinfo->height;
        else        ac=(float)tpreport->y/tpreport->x;
        if(tpreport->x==0)
                if(tpreport->y==tpinfo->height)        ad=-m;
                else                        ad=-tpinfo->height;
        else        ad=(float)(tpreport->y-tpinfo->height)/tpreport->x;
        if(ac<=m)
                if(ad<=-m)        return 2;
                else                 return 6;
        else 
                if(ad<-m)        return 4;
                else                return 8;
#else
        return 0;
#endif
}

/* 8
  4 6
   2
*/
int getTouchedZone4()//��TouchPad�ֳ�4�����򣬶�ȡֵ
{
#ifdef TOUCHPAD_SUPPORT
        if(!is_touchpad) return 0;
        if(!tpreport->contact) return 0;
        float m = (float)tpinfo->height/tpinfo->width;
        float ac,ad;
        if(tpreport->x==0)
                if(tpreport->y==0)        ac=m;
                else                        ac=tpinfo->height;
        else        ac=(float)tpreport->y/tpreport->x;
        if(tpreport->x==0)
                if(tpreport->y==tpinfo->height)        ad=-m;
                else                        ad=-tpinfo->height;
        else        ad=(float)(tpreport->y-tpinfo->height)/tpreport->x;
        if(ac<=m)
                if(ad<=-m)        return 2;
                else                 return 6;
        else 
                if(ad<-m)        return 4;
                else                return 8;
#else
        return 0;
#endif
}

/* 789
   456
   123
*/
int getTouchedZone9()//��TouchPad�ֳ�9�����򣬶�ȡֵ
{
#ifdef TOUCHPAD_SUPPORT
        if(!is_touchpad) return 0;
        if(!tpreport->contact) return 0;
        if(tpreport->x<=tpinfo->width/3)
                if(tpreport->y<=tpinfo->height/3)                return 1;
                else if(tpreport->y<=2*tpinfo->height/3)        return 4;
                else                                                return 7;
        else if(tpreport->x<2*tpinfo->width/3)
                if(tpreport->y<=tpinfo->height/3)                return 2;
                else if(tpreport->y<2*tpinfo->height/3)                return 5;
                else                                                return 8;
        else
                if(tpreport->y<=tpinfo->height/3)                return 3;
                else if(tpreport->y<2*tpinfo->height/3)                return 6;
                else                                                return 9;
#else
        return 0;
#endif
}

int isTPTouched()//TP�Ƿ񱻴���
{
#ifdef TOUCHPAD_SUPPORT
        return tpreport->contact;
#else
        return 0;
#endif
}

int isTPPressed()//TP�Ƿ񱻰���
{
#ifdef TOUCHPAD_SUPPORT
        return tpreport->pressed;
#else
        return 0;
#endif
}

int isTouchpad()//�Ƿ�ӵ��Touchpad
{
#ifdef TOUCHPAD_SUPPORT
        return 1;
#else
        return 0;
#endif
}
