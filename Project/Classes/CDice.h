#ifndef _CDICE_H_
#define _CDICE_H_
//주사위 
class CDice
{
public:
	CDice();
	CDice(int a_number,int a_type);
	int rollDice();
	int rollDice(int type);
	int rollDice(int type,int Number);
	void setNumber(int a_number){ m_number = a_number; }
	int getNumber(){ return m_number; }

	void setType(int a_type){ m_type = a_type; }
	int getType(){ return m_type; }
private:
	int m_number;
	int m_type; // 6 - 6면체  12 - 12면체 
};
#endif