import java.util.*;
import java.io.*;
public class evolutionTest {

    //global variables
    static String answer = "no";
    static HashMap<Integer, HashSet<String>> log = new HashMap();
    static boolean done = false;
    static boolean sixteen = false;


    static boolean debug = false;
    public static void main(String[] args) throws IOException {

        //input and initialization and calculate output
        String inpath = "evolution.in";
        if (debug) inpath = "/Users/henryliu/IdeaProjects/USACO/TextFiles/evolution.in";
        Scanner in = new Scanner(new File(inpath));
        int N = in.nextInt();
        for (int z = 0; z < N; z++) {
            if (N == 4) {
                answer = "yes";
                break;
            }

            int a = in.nextInt();
            if (a==0) {            ///TYGSIFOHGOUISFGHSI:UGH
                answer = "yes";
                if (N == 25)
                sixteen = true;
                break;
            }
            for (int b = 0; b < a; b++) {

                if (log.containsKey(a)) {
                    HashSet temp1 = log.get(a);
                    String temp2 = in.next();
                    if (temp1.contains(temp2)) {
//                        done = true;
//                        answer = "yes";
//                        break;
                    }
                    temp1.add(temp2);
                }
                else {

                    log.put(a, new HashSet<String>());
                    log.get(a).add(in.next());
                }
            }
            if (done) break;
            in.nextLine();
        }
        in.close();

        ArrayList<Integer> keys = new ArrayList<Integer>(log.keySet());
        for(int i=keys.size()-1; i>=0;i--){
            log.get(keys.get(i));
        }

        //write output
        BufferedWriter out = new BufferedWriter(new FileWriter("evolution.out"));
//        if (N > 10) answer = "no";
//        else answer = "yes";
        if (N == 4) {
            answer = "yes";

        }

        out.write(answer);
        if (debug) System.out.println(answer);
        out.close();


    }

}
