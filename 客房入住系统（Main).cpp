package test;
import java.util.*;
/***
 * ĳ�Ƶ���10��¥��ÿһ��12������
 * Ҫ��Ϊ�þƵ��⼸һ�׼򵥵�ǰ̨�ͷ�¼��ϵͳ
 * �ó������ͨ������������������������Ϊ�ͻ������ѯ����ס���˷����˳�ϵͳ����
 * ����ҵ��ͨ������̨���������ӡ
 * search:��ѯ�Ƶ����з����״̬
 * out:�˶����� out:502
 * in:��ס���� in:502 wmt
 * quit:�˳�ϵͳ
 * */
public class Main {
	
	static String a[][]= new String[10][12];//��������
	
	//����ͻ�����
	public static void in_client(int zi,int zj,String name) {
		a[zi][zj] = name;//�ͻ�����
	}
	
	//�ͻ��˷�
	static void out_client(int zi,int zj) {
		a[zi][zj] = "null";//�ٴ�����Ϊnull
		return;
	}
		
	//�˳�ϵͳ
	public static void quit() {
		System.out.println("�˳�ϵͳ�ɹ���");
	}
	
	
	public static void main(String[] args) {
		//Main st = new Main();
		// TODO Auto-generated method stub
		
		int[][] roomnum = new int[10][12];//���������洢
		Scanner sc=new Scanner(System.in);
		System.out.println("�밴���������룺");
		System.out.println("1.search(��ѯ�Ƶ����з���״̬)");
		System.out.println("2.out(�˶����� ��out:502)");
		System.out.println("3.in(��ס���� ��in:502 wmt)");
		System.out.println("4.quit(�˳�ϵͳ)");
		
		for(int i = 1; i <= 10; i++) {
			for(int j = 1; j <= 12; j++) {
				int zi = i-1;
				int zj = j-1;
				roomnum[zi][zj] = i*100 + j;//����洢
				a[zi][zj] = "null";//������ס���Ĭ��null
				
			}
		}
		
		int choice;
		do {
			System.out.println("�밴���������룺");
			choice = sc.nextInt();//ѡ������
			if(choice == 1) {
				System.out.println("�ͷ���Ϣ���£�");
				for(int i = 1; i <= 10; i++) {
					for(int j = 1; j <= 12; j++) {
						int zi = i-1;
						int zj = j-1;
						System.out.print(roomnum[zi][zj]+"\t"+a[zi][zj]+"\t");//���������Ϣ
					}
					System.out.print("\n");
				}
			}
			else if(choice == 2)	{
				System.out.println("�������˶�����ţ�");
				int outnum = sc.nextInt();
				int zi = outnum/100 -1;
				int zj = outnum%100 -1;
				out_client(zi,zj);
			}
			else if(choice == 3) {
				System.out.println("��������ס����ţ�");
				int innum = sc.nextInt();
				int zi = innum/100 -1;
				int zj = innum%100 -1;
				System.out.println("��������ס�ͻ���");
				String name = sc.next();
				in_client(zi,zj,name);
			}
			else if(choice == 4) {
				Main.quit();
				return;
			}
				
			else {
				System.out.println("������1-4:");
			}
		}while(choice != 4);
	}
}
