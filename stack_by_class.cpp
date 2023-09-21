#include<iostream>
#include<cmath>
using namespace std;
class stack{
    int *a,top,size;
public:
    stack(int size){
        this->size = size;
        a = new int[size];
        top = -1;
    }
    void push(int data){
        if(top == size-1)
            cout<<"overflow"<<endl;
        else    
            a[++top] = data;
    }
    int pop(){
        if(is_empty()){
            cout<<"underflow"<<endl;
            return -1;
        }
        else{
            return a[top--];
        }
    }
    bool is_empty(){
        if(top == -1)
            return 1;
        return 0;
    }
    bool is_full(){
        if(top == size-1)
            return 1;
        return 0;
    }
    int peek(){
        if(is_empty())
            exit(1);
        return a[top];
    }
    void display(){
        for(int i=0; i<=top; i++){
            cout<<a[i]<<" ";
        }
        cout<<endl;
    }
};
int main(){
    string s = "22 3/";
    stack st(s.size());
    int i = 0;
    while(i<s.size()){
        if(s[i] == ' '){
            i++;
        }
        else if(s[i]>='0' && s[i] <= '9'){
            int val = 0;
            while(s[i]>='0' && s[i] <= '9'){
                val = val*10 + (int)(s[i]-'0');
                i++;
            }
            st.push(val);
        }
        else{
            int a = st.pop();
            int b = st.pop();
            switch (s[i])
            {
            case '+':
                st.push(b+a);
                break;
            
            case '-':
                st.push(b-a);
                break;
            
            case '*':
                st.push(b*a);
                break;
            
            case '/':
                st.push(b/a);
                break;
            
            default:
                break;
            }
            i++;
        }
    }
    cout<<st.peek();
    return 0;
}