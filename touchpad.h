#define TOUCHPAD_DELAY        45

#ifdef TOUCHPAD_SUPPORT
touchpad_report_t* tpreport;
extern touchpad_info_t* tpinfo;
#endif

void initTP();//��ʼ��TP
void endTP();//�ͷ�
void readTP();//��ȡTP״̬
int getTouchedZone5();//��TouchPad�ֳ�5�����򣬶�ȡֵ
int getTouchedZone4();//��TouchPad�ֳ�4�����򣬶�ȡֵ
int getTouchedZone9();//��TouchPad�ֳ�9�����򣬶�ȡֵ
int getX_Velocity();//��ȡX���������
int getY_Velocity();//��ȡY���������
int getX();//��ȡX�ľ�������
int getY();//��ȡY�ľ�������
int isTPTouched();//TP�Ƿ񱻴���
int isTPPressed();//TP�Ƿ񱻰���
int isTouchPad();//�Ƿ�ӵ��Touchpad
