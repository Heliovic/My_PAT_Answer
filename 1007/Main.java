import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		int K = scanner.nextInt();
		int[] f = new int[K];
		int[] dp = new int[K];
		boolean hasPositive = false;
		for (int i = 0; i < K; i++) {
			f[i] = scanner.nextInt();
			if (f[i] >= 0)
				hasPositive = true;
		}
		
		if (!hasPositive) {
			System.out.print("0 " + f[0] + " " + f[f.length - 1]);
			return;
		}
		
		dp[K-1] = f[K-1];
		for (int i = K-2; i >= 0; i--) {
			// dp: �� i ���������ֵ
			// f: �� i ��ֵ
			// ��̬�滮�����ƹ�ϵʽ����ǰ����
			// ״̬ת�Ʒ���: dp[i] = max(f[i], f[i] + dp[i + 1])
			dp[i] = Math.max(f[i], f[i] + dp[i + 1]);
		}
		int maxIndex = 0;
		for (int i = 0; i < K; i++) {
			if (dp[maxIndex] < dp[i])
				maxIndex = i;
		}
		int sum = 0;
		int endIndex = maxIndex;
		for (int i = maxIndex; ; i++) {
			sum += f[i];
			if (sum == dp[maxIndex]) {
				endIndex = i;
				break;
			}
		}
		
		System.out.print(dp[maxIndex] + " " + f[maxIndex] + " " + f[endIndex]);
	}
}
