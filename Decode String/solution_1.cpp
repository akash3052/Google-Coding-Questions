class Solution {
public:
    string decodeString(string s) {
        string res = "",temp = "";
        int count = 0;
        stack<int> intStack;
        stack<char> stringStack;

        for(int i=0;i<s.length();i++){
            int count = 0;
            temp = "";
            // Note -> There can be more than 1 digit number, so we need to consider that case also.
            // For that while loop is written inside if condn.
            if(s[i]>='0' && s[i]<='9'){
                while(s[i]>='0' && s[i]<='9'){
                    count = count *10 + (s[i] - '0');
                    i++;
                }
                intStack.push(count);
                i--;
            }else if (s[i] == ']'){
                // when there is closing bracket, we keep on popping till we encounter opening bracket.
                while(!stringStack.empty() && stringStack.top()!= '['){
                    temp = stringStack.top() + temp;
                    stringStack.pop();
                }
                if(stringStack.top() == '[')
                   stringStack.pop();
                count = intStack.top();
                intStack.pop();
                // Now we have string in temp and count represents how many times we need to repeat the given string temp. 
                // In below for looop we are making final string "res" by repeating the string "temp" requried no of times.
                for(int i=0;i<count;i++){
                    res= res + temp;
                }
                // Now we are again pushing back the string which is formed after required no of repeatations into the stringStack.
                for(int i=0;i<res.length();i++){
                    stringStack.push(res[i]);
                }
                res = "";
            }
            // Note -> In this else block, we are the it in stringStack if it is not a number or ']'.
            // we are pushing if it is character or '['.
            else{
                stringStack.push(s[i]);
            }
        }
        while(!stringStack.empty()){
            // Note -> Initially it was written like below but we wanted the answer and reverse order.
            // res+=stringStack.top();
            
            //Note -> Imp Code(when we want the output of stack in reverse order, let say in FIFO order)
            res = stringStack.top() + res; // we are appending the s.top() at the start of the string "res" not at the end.
            stringStack.pop();
        }
        // reverse(res.begin(), res.end());
        return res;
    }
};
