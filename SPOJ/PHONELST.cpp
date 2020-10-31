#include<iostream>
using namespace std;

struct trie{
	struct trie *children[10];
	bool isEnd;
};

trie* getNode(){
	trie *nn = new trie;
	for(int i=0;i<10;i++){
		nn->children[i]=NULL;
	}
	nn->isEnd=false;
	return nn;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int T;
	cin>>T;
	int n;
	while(T--){
		cin>>n;
		string num;
		trie *root = getNode();
		trie *temp;
		int flag=1;
		while(n--){
			cin>>num;
			if(flag==1){
				temp = root;
				for(int i=0;i<num.length();i++){
					if(temp->isEnd==true){
						flag=0;
						break;
					}
					int idx = num[i] - '0';
					if(temp->children[idx]==NULL){
						temp->children[idx] = getNode();
					}
					temp = temp->children[idx];
				}
				temp->isEnd = true;
				for(int i=0;i<10;i++){
					if(temp->children[i]!=NULL){
						flag=0;
						break;
					}
				}
			}	
		}
		(flag==1) ? cout<<"YES"<<endl : cout<<"NO"<<endl;
	}
}

