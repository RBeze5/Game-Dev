import java.util.Scanner;
import javax.swing.JOptionPane;
public class TicTacToe
{
    public static int mat[][]=new int[3][3],x,y,move=-1;
    public static Scanner sc=new Scanner(System.in);
    public static void show()
    {
        int i,j;
        System.out.print("\u000C");
        System.out.println("+--------+--------+--------+");
        for(i=0;i<3;i++)
        {
            System.out.println("|        |        |        |");
            System.out.print("|");
            for(j=0;j<3;j++)
                   System.out.printf("    %c   |",(mat[i][j]==-1)?' ':(mat[i][j]%2==0)?'X':'O');
            System.out.print("\n|");
            for(j=0;j<3;j++)
                   System.out.printf("    %c   |",(i==x&&j==y)?'*':' ');
            System.out.println("\n+--------+--------+--------+");
        }
    }
    public static void set()
    {
        int i,j;
        x=0;
        y=0;
        for(i=0;i<3;i++)
            for(j=0;j<3;j++)
                mat[i][j]=-1;
    }
    public static void play()
    {
        if(mat[x][y]==-1)
           mat[x][y]=++move;
        else
           JOptionPane.showMessageDialog(null,"Invalid Capture, cell already occupied"); 
    }
    public static void navigate()
    {
        char c=sc.next().charAt(0);
        switch(c)
        {
            case 'a':
            case 'A': y=y-1;
                      if(y<0)
                        y=2;
                      break;
            case 'd':
            case 'D': y=y+1;
                      if(y>2)
                        y=0;
                      break;   
            case 'w':
            case 'W': x=x-1;
                      if(x<0)
                        x=2;
                      break;
            case 's':
            case 'S': x=x+1;
                      if(x>2)
                        x=0;
                      break;
            case 'z':
            case 'Z': play();
                      break;
            case 'x':
            case 'X': System.exit(0);
                      break;
            default:  JOptionPane.showMessageDialog(null,"Invalid Move");
        }
    }
    public static void main(String args[])
    {
        set();
        show();
        while(true)
        {
            navigate();
            show();
        }
    }
}