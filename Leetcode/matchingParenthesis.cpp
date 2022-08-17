/*  Description: Matching Parenthesis
        Created: 07/22/20
        Modified: 07/07/20
        Completed: 
*/
void matchingParenthesis(char c[],int n){
    int i;
    stack s;
    for(i=0;i<n;i++){
        if(c[i]=='('|| c[i]=='{' || c[i]=='['){
            s.push(c[i]);
        }
        else if(c[i]==')' && s.top()=='('){
            s.pop();
        }
        else if(c[i]=='}' && s.top()=='{'){
            s.pop();
        }
        else if(c[i]==']' && s.top()=='['){
            s.pop();
        }
    }
    if(s.empty()==true ){
        printf(" balanced");
    }
    else{
        printf(" not balanced");
    }
}

int main(){
    char c[100];
    int i,n;
    printf("enter the expression");
    gets(c);
    n = strlen(c);
    matchingParenthesis(c,n);
}

public static boolean CheckParentesis(String str){
    if (str.isEmpty()){
        return true;
    }
    Stack<Character> stack = new Stack<Character>();
    for (int i = 0; i < str.length(); i++){
        char current = str.charAt(i);
        if (current == '{' || current == '(' || current == '['){
            stack.push(current);
        }
        if (current == '}' || current == ')' || current == ']'){
            if (stack.isEmpty()){
                return false;
            }
            char last = stack.peek();
            if (current == '}' && last == '{' || current == ')' && last == '(' || current == ']' && last == '['){
                stack.pop();
            }
            else{
                return false;
            }
        }
    }
    return stack.isEmpty();
}