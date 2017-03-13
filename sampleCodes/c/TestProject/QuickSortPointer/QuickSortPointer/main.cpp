void Swap(int *a, int *b)
{

	int temp = *a;
	*a = *b;
	*b = temp;
}

int *Partition(int *prtL, int *prtR, int *prtP) {

	if (*prtL<*prtP)
		prtL++;
	else if (*prtR >= *prtP)
		prtR--;

	else
		Swap(prtL, prtR);



	return prtL;
}



 int QS(int *prtL, int *prtR) {

	int *PartitionVar = nullptr;

	if(*prtL - *prtR <= 0)
		return 0;
	else {

		PartitionVar = Partition(prtL, prtR, prtR);
		QS(prtL, PartitionVar - 1);
		QS(PartitionVar + 1, prtR);
	}
	return *prtL;
}

int main() {

	int array[] = { 35,33,42,10,14,19,27,44,26,31 };
	QS((array + 8), (array + 9));
	return 0;
}