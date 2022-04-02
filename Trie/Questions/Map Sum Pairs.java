import java.io.*;
import java.util.*;
 
public class Main {
  public static class MapSum {
    
    public static class Node{
        Node[] childs = new Node[26];
        int score = 0;
    }
    Node root = new Node();
    HashMap<String , Integer> keyval = new HashMap<>();
    
    /** Initialize your data structure here. */
    public MapSum() {
 
    }
 
    public void insert(String key, int val) {
        int delta = val - keyval.getOrDefault(key , 0);
        keyval.put(key,val);
        
        Node curr = root;
        for(int i = 0; i < key.length() ; i++){
            char ch = key.charAt(i);
            if(curr.childs[ch - 'a'] == null){
                curr.childs[ch-'a'] = new Node();
            }
            curr =  curr.childs[ch-'a'];
            curr.score += delta;
        }
    }
 
    public int sum(String prefix) {
        Node curr = root;
        for(int i = 0; i < prefix.length() ; i++){
            char ch = prefix.charAt(i);
            
            if(curr.childs[ch-'a'] == null){
                return 0;
            }
            curr = curr.childs[ch-'a'];
        }
        
        return curr.score;
    }
  }
 
  public static void main(String[] args) throws Exception {
    BufferedReader read = new BufferedReader(new InputStreamReader(System.in));
 
    MapSum obj = new MapSum();
 
    while (read.ready()) {
      String inp[] = read.readLine().split(" ");
      if (inp[0].equals("exit"))break;
 
      if (inp.length == 2) {
        obj.insert(inp[0], Integer.parseInt(inp[1]));
      } else {
        System.out.println(obj.sum(inp[0]));
      }
    }
  }
}
 
