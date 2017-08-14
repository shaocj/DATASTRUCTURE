# define LIST_INIT_SIZE  100              // ˳���(Ĭ�ϵ�)�ĳ�ʼ�����������
# define LISTINCREMENT  10                // (Ĭ�ϵ�)�����ռ���
typedef struct {
ElemType  *elem;                      // �洢����Ԫ�ص�һά����
    int length;                           // ���Ա��ĵ�ǰ����
    int listsize;                         // ��ǰ�����������������ElemTypeΪ��λ��
    int incrementsize;                   // �����ռ�������ElemTypeΪ��λ��
} SqList; 




void InitList_Sq( SqList &L, int maxsize=LIST_INIT_SIZE, int incresize=LISTINCREMENT ) 
{      // ����һ���������Ϊmaxsize��˳��� L
     L.elem=(ElemType *)malloc(maxsize*sizeof(ElemType));
                                    // Ϊ˳�������һ���������Ϊ maxsize ������ռ�
     if(!L.elem)  exit(1);           // �洢����ʧ��
      L.length=0;                    // ˳����е�ǰ����Ԫ�ظ���Ϊ 0
      L.listsize=maxsize;            // ��˳�����������maxsize������Ԫ��
      L.incrementsize=incresize;     // ��Ҫʱ������incresize��Ԫ�ؿռ�
}// InitList_Sq





int ListLength_Sq(SqList L)
 { 
      return L.length;
}// ListLength_Sq

bool ListEmpty_Sq(SqList L)
{
  if(L.length==0)
  return true;
  else return false;
}





int LocateElem_Sq( SqList L, ElemType e) 
{  
   for(int i=0;i<L.length;i++)
    if(L.elem[i]==e)  return i;   // �ҵ������ж�������Ԫ��Ϊ�� i ��Ԫ��
   return -1;                     // �����Ա��в����������ж�������Ԫ��
 }//LocateElem_Sq





bool ListInsert_Sq(SqList &L, int i, ElemType e)
{   // ��˳���L�ĵ�i��Ԫ��֮ǰ�����µ�Ԫ��e��
// �����е�ǰ�������㣬��Ԥ�������������
int j;
      if(i<0||i>L.length)  return false;            // iֵ���Ϸ�
      if(L.length>=L.listsize)  {                   // ��ǰ�洢�ռ������������ռ�
    L.elem=(ElemType *)realloc(L.elem,(L.listsize+L.incrementsize)*sizeof(ElemType));
         if(!L.elem) exit(1);                   // �洢����ʧ��
         L.listsize+=L.incrementsize;           // ��ǰ�洢��������
        }
         for(j=L.length;j>i;j--)                // ������Ԫ��֮���Ԫ������
L.elem[j]=L.elem[j-1];
         L.elem[i]=e;                           // ����Ԫ��e
         L.length++;                            // ������1
        return true;   
}// ListInsert_Sq




bool ListInsert_Sq_1(SqList &L, ElemType e)
{   // �ڵ�������˳���L�в����µ�Ԫ��e��
// �����е�ǰ�������㣬��Ԥ�������������
      int i,j;
      if(L.length>=L.listsize)  {                   // ��ǰ�洢�ռ������������ռ�
    L.elem=(ElemType *)realloc(L.elem,(L.listsize+L.incrementsize)*sizeof(ElemType));
         if(!L.elem) exit(1);                   // �洢����ʧ��
         L.listsize+=L.incrementsize;           // ��ǰ�洢��������
        }
      for(i=0;i<L.length&&e>L.elem[i];i++); 
	  for(j=L.length;j>i;j--)                // ������Ԫ��֮���Ԫ������
L.elem[j]=L.elem[j-1];
         L.elem[i]=e;                           // ����Ԫ��e
         L.length++;                            // ������1
        return true;   
}// ListInsert_Sq




bool ListDelete_Sq(SqList &L,int i, ElemType &e)
{      // ��˳���L��ɾ����i��Ԫ�أ�����e������ֵ
      int  j;
if(i<0||i>L.length) return false;            // iֵ���Ϸ�
if(L.length<=0)  return false;                // ����������Ԫ�ؿ�ɾ
     e=L.elem[i];                                  // ��ɾ��Ԫ�ص�ֵ����e
      for(j=i+1;j<=L.length-1;j++)                 // ��ɾ��Ԫ��֮���Ԫ��ǰ��
        L.elem [j-1]=L.elem [j];
      L.length--;                                  // ������1
      return true;    
}// ListDelete_Sq



bool GetElem_Sq(SqList L,int i, ElemType &e)
{     // ȡ��˳���L�е�i��Ԫ�أ�����e������ֵ��
     if(i<0||i>L.length) return false;            // iֵ���Ϸ�
      if(L.length<=0)  return false;               // ����������Ԫ�ؿ�ȡ
      e=L.elem[i];                                 // ��ȡԪ�ص�ֵ����e
      return true;    
}// GetElem_Sq  




void ListTraverse_Sq(SqList L)
{
 int i;
 for(i=0;i<L.length;i++)
  cout<<setw(6)<<L.elem[i];
  cout<<endl;
}// ListTraverse_Sq



void DestroyList_Sq(SqList &L)
{       // �ͷ�˳���L��ռ�洢�ռ�
      free(L.elem);
	  L.elem=NULL;
      L.listsize=0;
      L.length=0;
}// DestroyList_Sq


void visualization(SqList L, char* filename)
{   int temp;
	FILE *stream;  
    if( NULL == (stream = fopen(filename, "w")) )  
    {  
	   printf("open file error");  exit(0);  
    }  
    fprintf(stream, "digraph\n{\nnode [shape = box];\n");  
	for(int i=0;i<L.length;i++)
	if(GetElem_Sq(L,i,temp))
    {
	    fprintf(stream, "box%d [label = \"%d\"];\n",i,temp);
	}
	fprintf(stream, "}"); 
	fclose(stream);  
	system("dot -Tpng showsqlist.dot -o showsqlist.png");
	system("showsqlist.png");
}


   