#include<iostream>
#include<vector>
#include<list>


using namespace std;

struct node{
	int v;
	struct node* l;
	struct node* r;
};

class Bin_tree {
	public:
		Bin_tree(){node = 0;}

		struct node* node;
		list <struct node*>q;
		int max(int i, int j)
		{
			return ( i>j ? i : j);
		}
		int  height(struct node* n)
		{
			if (n == 0){
				return 0;
			}

			int l = height(n->l);
			int r = height(n->r);
			if (l > r)
				return(l + 1);
			else
			   	return (r + 1);
			//return(max(l, r) + 1);

		}


		/*This increment from top to down*/

		int  height(struct node* n, int i)
		{
			if (n == 0){
				return i;
			}
			if (n->r!=0 || n->l!=0)		++i;

			return(max(height(n->l, i), height(n->r, i)));

		}

		void print()
		{

			int ht = height(node);
			cout << " height " <<ht;
			cout<<"inorder ->  ";
			print_inorder(node);
#if 0
			cout <<"\n" << "preorder ->";
			print_preorder(node);
			cout <<"\n" << "postorder ->";
			print_postorder(node);
			cout <<"\n" << "level order ->";
			print_levelorder(node);
			cout <<"\n" << "level order(recursion) ->";
			print_levelorder_rec();
			print_q(q);
#endif
		}

		void print_q(list<struct node*>& l)
		{

			list<struct node*>::iterator it = l.begin();
			struct node*_t;

			cout<<"queue size " << l.size()<<endl;

			//for (; it != l.end(); ++it) {
			while( q.size() != 0) {
				_t = q.front();
				q.pop_front();
				cout <<"Ptr -> "<<_t <<" value ->"<<_t->v;
			}
			cout<<"\n";

		}

		/**
		 * using height
		 */
		void print_levelorder_rec_2()
		{

		}



		/**
		 * push to node
		 */
		void print_levelorder_rec()
		{
			if(q.empty()) {
				q.push_back(node);
				print_levelorder_rec();
			}
			int sz = q.size();
			for(int i = 0; i < sz; ++i) {
				struct node* _t;
				_t = q.front();
                q.pop_front();
				cout << _t->v <<" ";
				if(_t->l)q.push_back(_t->l);
				if(_t->r)q.push_back(_t->r);
			}

			if (q.size() != 0)print_levelorder_rec();


		}



		/*breadth first or level order
		 *
		 */

		void print_levelorder(struct node* n)
		{
			if (n == 0)return;
			cout <<n->v <<" ";
			if (n->l)q.push_back(n->l);
			if (n->r)q.push_back(n->r);

			while (q.size() != 0) {
				struct node*_n = q.front();
				q.pop_front();
				cout <<_n<<" "<<_n->v <<" ";
				if (_n->l)q.push_back(_n->l);
				if (_n->r)q.push_back(_n->r);
			}

		}

		/*post order -> left, right, root
		 *
		 *
		 */
		void print_postorder(struct node *n)
		{
			if (n == 0)return;
			print_postorder(n->l);
			print_postorder(n->r);
			cout<<n->v<<" ";
		}

		/*
		 *100->20,200
		 *20->10,30
		 *200->150, 300
		 */

		/*pre order - root, left, right*/
		void print_preorder(struct node *n)
		{
			if (n == 0)return;
			cout << n->v << " ";
			print_preorder(n->l);
			print_preorder(n->r);

		}

		/*inorder -> left node, root, right node
		 *
		 *
		 */
		void print_inorder(struct node *n)
		{

			if (n == 0) { return;}
			print_inorder(n->l);
			cout <<n->v <<" ";
			print_inorder(n->r);
		}

		void print_tree(struct node *n)
		{
			if( n != 0) {
				cout << "root " << n << "value " << n->v << "\n";
				if(n->l != 0)
					cout << "left " << n->l << "value " << n->l->v << "\n";
				if(n->r != 0)
					cout << "right " << n->r << "value " << n->r->v <<"\n";
				print_tree(n->l);
				print_tree(n->r);
			}
		}

		void add(int v)
		{
			if (node == 0)
				add_node(&node, &node, v);
			else if (v > node->v) add_node(&node, &node->r, v);
			else if (v < node->v) add_node(&node, &node->l, v);

		}
		void add_node(struct node** p, struct node** node, int v)
		{
			struct node *_node;
			if (*node == 0){
				_node  = new struct node;
				_node->v = v;
				_node->l = 0;
				_node->r = 0;
				if(*p != 0) {
					if (v > (*p)->v )(*p)->r = _node;
					else (*p)->l = _node;
				}
				else *node = _node;
			}
			else if ( v > (*node)->v) {
				add_node(node, &((*node)->r), v);
			}
			else
				add_node(node, &((*node)->l), v);
		}
};

int main()
{
	Bin_tree t;

	/*
	 *				 100
	 *				/	\
	 *             20	200
	 *			  /  \	 /  \
	 *			 10	 30 150	 300
	 */
	//list<int> l({100, 20, 200, 10, 30, 150, 300});
	//list<int> l({50, 35, 57, 30, 40, 52, 58, 11});
	list<int> l({150,250,270,320,350});
	list<int>::iterator i = l.begin();
#if 0
	t.add(10);
	cout << "node added  " <<t.node <<"  "<<t.node->l  <<"  "<< t.node->r <<"\n";
	t.add(11);
	cout << "node added  " <<t.node <<"  "<<t.node->l  <<"  "<< t.node->r <<"\n";
	t.add(9);
	cout << "node added  " <<t.node <<"  "<<t.node->l  <<"  "<< t.node->r <<"\n";
	t.add(8);
	cout << "node added  " <<t.node <<"  "<<t.node->l  <<"  "<< t.node->r <<"\n";
#endif
	for(; i != l.end(); i++)
		t.add(*i);	
	t.print();

	return 0;
}
