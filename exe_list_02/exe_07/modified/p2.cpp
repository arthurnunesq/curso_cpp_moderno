// enum Numbers { 
// 	One = 1,
// 	Two = 2,
// };

namespace Numbers{
	enum Number { 
		One = 1,
		Two = 2,
	};
}
typedef Numbers::Number Number;

void k(int v){
	switch(v){
		case Numbers::One: ;
		case Numbers::Two: ;
	}
}

int main(){
	k(Numbers::One);
	return 0;
}