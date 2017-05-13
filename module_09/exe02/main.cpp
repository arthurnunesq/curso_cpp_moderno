#include <iostream>
#include <string>

struct Top {
	virtual void f() const;
	void g(int);
	void k();
};


struct Down : public Top {
	//void f() override;
	//main.cpp:12:7: error: 'void Down::f()' marked 'override', but does not override
	//  void f() override;
	//       ^	
	void f() const override;

	using Top::g;
	void g(std::string);

	//void k(int) override;
	//main.cpp:20:7: error: 'void Down::k(int)' marked 'override', but does not override
	//  void k(int) override;
	//       ^
	using Top::k;
	void k(int);
};

int main()
{
    return 0;
}

