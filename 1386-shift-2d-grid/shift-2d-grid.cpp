class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int r = grid.size(); 
        int c = grid[0].size();

        // pos for ele with ind(i, j) = i*c + j
        /* 
            0   1   2
        0   0   1   2
        1   3   4   5
        2   6   7   8

        for imagining shifted pos, put the numbers into a single line instead of matrix

        0   1   2   3   4   5   6   7   8
        r*c = 9

        so the ques has been reduced into right shift in a linear(1d) arr
         */

        //from my end -> breaking down the problem into linear arr -> is good enough
        //spent more than enough time -> look at the soln for const O(1) SC
        //and learnnnnn 
        //time management: fight with ques, whatever ques/approaches you have write on paper(in short), try to solve it on your own -> w/o any help -> but as soon as it takes more than required time -> start taking help. Focus on implementation first -> type/write code/pseudocode brute, better and optimal approaches. For notes -> if you have written a lot on something maybe theory maybe approaches or egs etc, or maybe you have a lots of ques - when to do what, how to know when to apply this, how to do pattern hunting, how do ik if ques says or asks this then i have to do this etc etc -> give all these questions to gpt -> and in notes you yourself write Bullet points, pseudocode, tc sc, few diagrams or dry run or egs - basically keywords or memory map and for longer notes many diagrams dry run egs etc -> give to gpt understand and then paste the summary on to the notes. whenever you do a ques, write its notes at that time only dont leave it for later... If you still have so many questions related to a topic or you did not understand it properly -> write those ques in as few words as possible and then leave it for lvl 2 learning, where you will learn everything about it... for lvl 1 you just need to know that if the same or related ques come then if you would be able to solve it or not -> so for lvl 1 it requires immense practice and a lot of Ques solving... For lvl 2 you require deep understanding and deep intuition about the thing you are learning... For lvl 3 you start building your own things from very basics. For eg: if you have just started dribbling then studying how kyrie dribbles what angle do his hands go, or if you started shooting then studying how curry shoots his legs his hands his fingertips when he shoots -> these dont matter, shooting and dribbling in whatever way you can matters more... just take reference from em that yeah these guys do like this, but they didnt start like this, and trying to replicate them you are skipping the imp middle stages... rn imp thing is that you just do as much as you can do, and get inspired from em, try their things if they work then include them into drills if they dont then just to yourself--- Later -> perfection is built from doing basic drills(exploit) again and again instead of doing the fancy thing for a few times(explore)... For me rn as indian job market goes, my basic drill is to solve as many ques as possible and write lvl1 notes, umm just try solving high priority ques and topics first and then make as many projects as possible and write lvl1 notes about CONCEPTS coz tools are changing fast and a tool i am using rn might become obsolete tomorrow but the concepts remain intact(exploit)... As i dont like indian job market and it industry so to switch to reserach or something else related to science (or tech if job market and culture isnt bad) - this i can do later once i secure a Job and good money first(explore) 
        //lvl1: usage of tools(dsa, cp: num of ques solved, implementation, short notes or mem map - explaining how it works instead of why; dev: num of projects made and concepts behind those projs)
        //lvl2: deep understanding of a tool(the level of WHY?- intuition and every questions related to that tool. you just assume a few basic assumptions and make everything from them; dsa, cp: concepts-> but where does tree come from? isnt it just a special case of graph? but what is a graph? why and who started representing comp sci concepts as a structure? is this structure just mathematical representation of things happening on hardware level or it does look like this on hardware level too? for cp i can learn maths: gcd -> invariant, how does gcd remains same, then learn oh not only gcd but the whole common divisors remain same down the line, same goes for every other thing -> i can learn them from basic mahts; dev: but what is a databse? what is api? what is a route? i dont see a physical port then what is port 80 again just mathematical representation? why a specific kind of software known as browser became so popular and so much more imp than all the other things? and so on...)
        //lvl3: making my own tools from the very basic assumptions(how to make my own data structure? what if i use different maths and try to solve this question this way? can i make my own database given that i have laptop with this spec? what about my own sql language to query my database? what are the principles used behind it and what if i change a few of them? ---> high level projs toh i can always make, there are so many tools for that but what i make those tools only and then make my projects from them?)
        //i have a habbit of falling into rabbit holes instead of doing the right thing rn (sticking to my basic drills of lvl1)

        //lvl1:
        //time management: fight -> rough work -> implement -> notes : all within some specified time

        vector<vector<int>> ans(r, vector<int>(c));
        for(int i = 0; i<r; i++){
            for(int j=0; j<c; j++){
                int ogpos = i*c + j;
                int newpos = (ogpos + k) % (r*c);
                int row = newpos/c; // eg: 5/3 = 1 => 1st row
                int col = newpos - row*c; // eg: 5 - 3*1 => 2nd col
                ans[row][col] = grid[i][j];
            }
        }

        return ans;
    }
};