class Poly;
typedef Poly P;

class LiLei{
	friend class Poly;  //c++98通过，C++11通过
};

class Jim{
	friend Poly;  //c++98失败，C++11通过
};

class HanMeiMei{
	friend P;  //c++98失败，C++11通过
};