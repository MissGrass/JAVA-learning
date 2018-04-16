package test;
import java.util.*;
/***
 * 某酒店有10层楼，每一层12个房间
 * 要求为该酒店这几一套简单的前台客房录入系统
 * 该程序可以通过命令输入命令行输入命令为客户办理查询、入住、退房、退出系统功能
 * 所有业务通过控制台输入输出打印
 * search:查询酒店所有房间的状态
 * out:退订房间 out:502
 * in:入住房间 in:502 wmt
 * quit:退出系统
 * */
public class Main {
	
	static String a[][]= new String[10][12];//定义数组
	
	//保存客户名字
	public static void in_client(int zi,int zj,String name) {
		a[zi][zj] = name;//客户名字
	}
	
	//客户退房
	static void out_client(int zi,int zj) {
		a[zi][zj] = "null";//再次设置为null
		return;
	}
		
	//退出系统
	public static void quit() {
		System.out.println("退出系统成功！");
	}
	
	
	public static void main(String[] args) {
		//Main st = new Main();
		// TODO Auto-generated method stub
		
		int[][] roomnum = new int[10][12];//房间号数组存储
		Scanner sc=new Scanner(System.in);
		System.out.println("请按照命令输入：");
		System.out.println("1.search(查询酒店所有房间状态)");
		System.out.println("2.out(退订房间 例out:502)");
		System.out.println("3.in(入住房间 例in:502 wmt)");
		System.out.println("4.quit(退出系统)");
		
		for(int i = 1; i <= 10; i++) {
			for(int j = 1; j <= 12; j++) {
				int zi = i-1;
				int zj = j-1;
				roomnum[zi][zj] = i*100 + j;//房间存储
				a[zi][zj] = "null";//房间入住情况默认null
				
			}
		}
		
		int choice;
		do {
			System.out.println("请按照命令输入：");
			choice = sc.nextInt();//选择命令
			if(choice == 1) {
				System.out.println("客房信息如下：");
				for(int i = 1; i <= 10; i++) {
					for(int j = 1; j <= 12; j++) {
						int zi = i-1;
						int zj = j-1;
						System.out.print(roomnum[zi][zj]+"\t"+a[zi][zj]+"\t");//输出房间信息
					}
					System.out.print("\n");
				}
			}
			else if(choice == 2)	{
				System.out.println("请输入退订房间号：");
				int outnum = sc.nextInt();
				int zi = outnum/100 -1;
				int zj = outnum%100 -1;
				out_client(zi,zj);
			}
			else if(choice == 3) {
				System.out.println("请输入入住房间号：");
				int innum = sc.nextInt();
				int zi = innum/100 -1;
				int zj = innum%100 -1;
				System.out.println("请输入入住客户：");
				String name = sc.next();
				in_client(zi,zj,name);
			}
			else if(choice == 4) {
				Main.quit();
				return;
			}
				
			else {
				System.out.println("请输入1-4:");
			}
		}while(choice != 4);
	}
}
