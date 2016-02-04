#ifndef _CDICE_H_
#define _CDICE_H_
//주사위 
class CDice
{
public:
	CDice();
	CDice(int a_number,int a_type);
	int rollDice(); // 주사위 던짐
	int rollDice(int type); // 쥐사위 타입 결정 후 던짐 
	int rollDice(int type,int Number); // 주사위 타입가 갯수를 정해서 던짐 



	// set get
	void setNumber(int a_number){ m_number = a_number; }
	int getNumber(){ return m_number; }

	void setType(int a_type){ m_type = a_type; }
	int getType(){ return m_type; }
	// set get
private:
	int m_number;
	int m_type; // 6 - 6면체  12 - 12면체 
};
#endif