#ifndef _CSTATUS_H_
#define _CSTATUS_H_

class Status
{
public:
	Status();
	Status(int hp, int spd, int def, int str, int dex, int ins, int kno);
	~Status();

	void setHp(int hp){ this->hp = hp; }
	int getHp(){ return hp; }

	void setSpeed(int speed){ this->spd = spd; }
	int getSpeed(){ return spd; }

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
	int spd;
	int def;

	int str; //Èû
	int dex;// ¹ÎÃ¸
	int ins; // instint º»´É 
	int kno; // Áö½Ä 

};
#endif