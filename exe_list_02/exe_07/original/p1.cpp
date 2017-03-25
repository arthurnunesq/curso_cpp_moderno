#define ADD2(A, B) A+B

void g(){
	int x = ADD2(1,10);
}

int main(){
	void g();
	return 0;
}