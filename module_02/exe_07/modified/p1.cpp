inline int ADD2(int A, int B) {
	return A+B;
}

void g(){
	int x = ADD2(1,10);
}

int main(){
	void g();
	return 0;
}