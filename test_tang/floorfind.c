//层序遍历

//将根节点放入队列，讲根节点弹出，放入根节点的左右儿子
//然后重复所有过程



/*
1.从队列中取出一个元素
2.访问元素所指向的左右节点
3.若该元素指向的左右节点非空，则讲该元素左右节点放入队列中
*/

/*
void  level(bintree  BT)
{

	//创建一个队列
	queue  q；
	//创建一个二叉树
	bintree  T；

	q = creatqueue(个数)；

	addq（q，BT）

	while( ! isempty(q))
	{
		T = delateQ(q);
		printf(T->data)               //取出节点
		if(T->left ) addq(q,T->left);
		if(T->right) addq(q,T->right)

	}

}

*/