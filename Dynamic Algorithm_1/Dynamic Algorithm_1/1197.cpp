#include <stdio.h>
#include <stdlib.h>
#define MAX_VER 10001
#define MAX_EDGE 100001
#define SWAP(a,b,type) { type temp; temp = a; a=b; b=temp;}
/*���� ����v  ���� ����e �־���
a�� ���� b�� ���� ����ġ c ...���� ������ŭ


Ʈ�� ����ü�� sum ������ �ϳ� �����صΰ� 
�ּ� ����Ʈ���� ����ġ ���� ������ �� ���� sum ++�ϸ� �ɵ� */

int parent[MAX_VER];
int v = 0;
long long sum = 0;
typedef struct Edge {
	int start, end, weight;
}Edge;

typedef struct GraphType {
	Edge edge[MAX_EDGE];
	int e_num;
	
}GraphType;

void init_grape(GraphType* g) {
	g->e_num = 0;
}

void insert_edge(GraphType* g, int start, int end, int weight) {
	g->edge[g->e_num].start = start;
	g->edge[g->e_num].end = end;
	g->edge[g->e_num].weight = weight;
	g->e_num++; //ex) �׷����� ���� 1������ == g->e_num 1��
}

int partition(GraphType* g, int start, int end) {
	int pivot = g->edge[start].weight;
	int low = start;
	int high = end+1;

	do {
		do {
			if (low == end) break;
			low++;
			
		} while (low < high && g->edge[low].weight < pivot);

		do {
			if (high == start) break;
			high--;
			
		} while (high > low && g->edge[high].weight > pivot);

		if (low < high) {
			SWAP(g->edge[low].start, g->edge[high].start, int);
			SWAP(g->edge[low].end, g->edge[high].end, int);
			SWAP(g->edge[low].weight, g->edge[high].weight, int);
		}

	} while (low < high);

	//pivot high low => pivot�� high�� �ٲ�
	if (start <= high) {
		SWAP(g->edge[high].start, g->edge[pivot].start, int);
		SWAP(g->edge[high].end, g->edge[pivot].end, int);
		SWAP(g->edge[high].weight, g->edge[pivot].weight, int);

	}
	
	return high;
}

void quick_sort(GraphType* g, int start, int end) {
	if (start < end) {
		int pivot = partition(g, start, end);
		quick_sort(g, start, pivot - 1);
		quick_sort(g, pivot + 1, end);
	}
}

void init(int n) {
	for (int i = 1; i <= n; i++) {
		parent[i] = -1;
	}
}

int set_find(int curr) {
	if (parent[curr] == -1)
		return curr;
	else {
		return parent[curr] = set_find(parent[curr]);
	}
}

void set_union(int a, int b) {
	int root1 = set_find(a);
	int root2 = set_find(b);
	if (root1 != root2)
		parent[root1] = root2;
}

void kruskal_MST(GraphType* g) { 
	int edge_accepted = 0;
	int uset, vset;
	struct Edge e;
	init(v);

	
	//�� ������ ������ŭ�� ũ�⸦ ���� �迭�� �־�� ����Ʈ �ϱ� �����ٵ�..
	//������ ����Ʈ �Ű������� ���� ������ ũ�⸦ �����ϱ� ��.
	if (g->e_num > 0) {
		quick_sort(g, 0, g->e_num - 1); //�ε��� �������� ����
	}
	else {
		quick_sort(g, 0, 0);
	}
	
	
	/*for (int i = 0; i < g->e_num; i++) {
		printf("(%d %d) %d\n", g->edge[i].start, g->edge[i].end, g->edge[i].weight);
	}*/

	int i = 0;
	while (edge_accepted<(g->e_num-1))
	{
		e = g->edge[i];
		uset = set_find(e.start); //���� u�� ��Ʈ ��Ʈ
		vset = set_find(e.end);
		if (uset != vset) {
			//printf("���� (%d %d) %d����\n", e.start, e.end, e.weight);
			edge_accepted++;
			set_union(uset, vset); //�ΰ��� ������ ���Ѵ�.
			sum += g->edge[i].weight;
		}
		i++;
	}
	//�׷��� ��������-1 ��ŭ ������
	//����Ŭ ������� �ȸ���� �� Ȯ���ϰ� ������ ������ �� 

	printf("%d", sum);


}

int main(void) {

	GraphType* g = (GraphType*)malloc(sizeof(GraphType));
	init_grape(g);
	int e = 0;
	scanf("%d %d", &v,&e);

	int start = 0, end = 0, weight = 0;
	for(int i = 0; i < e; i++) {
		scanf("%d %d %d", &start, &end, &weight);
		insert_edge(g,start, end, weight);
	}
	if (v != 0 || e != 0) {
		kruskal_MST(g);
	}
	
	free(g);

	return 0;
}