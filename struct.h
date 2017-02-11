#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED

struct Pixel {

	unsigned char Brightness; //Яркость пикселя
	bool Need;
};

struct Sqare {//Обычный полигон

	int x;
	int y;
	int Height;
	int Width;

};


struct SqareList{
	Sqare info;
	SqareList *next;
};


class SqareStackP{//Пользовательсий стек для полигонов

private:
	SqareList *Head;
public:
	SqareStackP(){
		Head = 0;
	};

	void Pop(){
		if (Head == 0)
			return;
		SqareList *p;
		p = Head;
		Head = Head->next;
		delete p;
	}
	void Push(Sqare Sq){
		SqareList *p = new SqareList;
		p->info = Sq;
		p->next = Head;
		Head = p;
	};

	bool empty(){
		if (Head == 0)
			return true;
		else
			return false;
	};

	Sqare top(){
		return Head->info;
	};
	

};

#endif