#include <stdio.h>
#include <ctype.h>
char stack[20];
int top = -1;

void
push (char x)
{
  stack[++top] = x;
}

char pop ()
{
  return stack[top--];

}

int
priority (char x)
{
    if (x=='#'){
        return 0;
    }
 
      else if (x == '(')
      {
        return 1;
      }
else if (x == '+' || x == '-')
  {
    return 2;
  }
else if (x == '*' || x == '/')
  {
    return 3;
  }

}

void
infixtopostfix (char *infix, char *postfix)
{
  char ch, ele;
  int i = 0, k = 0;
  push('#');
  while ((ch = infix[i++]) != '\n')
    {
      if (ch == '(')
    	{
    	  push(ch);
    	}
      else if (isalnum(ch))
	{
	  postfix[k++]=ch;
	}

      else if (ch == ')')
	{
	  while (stack[top] != '(')
	    {
	      postfix[k++] = pop ();
	    }
	  ele = pop ();
	}
      else
	{
	  while (priority (stack[top]) >= priority (ch))
	    {
	      postfix[k++] = pop ();
	    }
	    push(ch);
	}

    }
  while (stack[top] != '#')
    {
      postfix[k++] = pop ();
      postfix[k]=0;
    }
}

int evalp(char *postfix){
    char ch;
    int i=0,op1,op2;
    while((ch=postfix[i++])!='\0'){
        if(isdigit(ch)){
            push(ch-'0');
        }
        else{
            op2=pop();
            op1=pop();
            switch(ch){
                case '+': push(op1+op2);
                break;
                case '-': push(op1-op2);
                break;
                case '*': push(op1*op2);
                break;
                case '/': push(op1/op2);
                break;
            }
        }
    }
    return stack[top];
}


int
main ()
{
  char infix[50], postfix[50];

  fgets (infix, 50, stdin);
  infixtopostfix(infix, postfix);
  printf ("%s", postfix);
  top=-1;
  printf("\n%d",evalp(postfix));
  return 0;
}
