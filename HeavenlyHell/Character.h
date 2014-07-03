namespace Model
{

class Character
{
private:
	unsigned int _x;
	unsigned int _y;

public:
	Character(void);
	~Character(void);

	unsigned int getX();
	unsigned int getY();

	void setX(unsigned int x);
	void setY(unsigned int y);
};

}