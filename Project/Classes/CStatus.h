#ifndef _CSTATUS_H_
#define _CSTATUS_H_

class Status
{
public:

	void setHp(int hp){ this->hp = hp; }
	int getHp(){ return hp; }

	void setSpeed(int speed){ this->speed = speed; }
	int getSpeed(){ return speed; }

	void setDef(int def){ this->def = def; }
	int getDef(){ return def; }

	void setStr(int str){ this->str = str; }
	int getStr(){ return str; }

	void setDex(int dex){ this->dex = dex; }
	int getDex(){ return dex; }

	void setIns(int ins){ this->ins = ins; }
	int getIns(){ return ins; }

	void setKno(int kno){ this->kno = kno; }
	int getKno(){ return kno; }

private:
	int hp;
	int speed;
	int def;

	int str; //��
	int dex;// ��ø
	int ins; // instint ���� 
	int kno; // ���� 

}


#endif