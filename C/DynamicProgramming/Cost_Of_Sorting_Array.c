// http://stackoverflow.com/questions/8928061/convert-array-to-a-sorted-one-using-only-two-operations

/*
Given an array A of positive integers. Convert it to a sorted array with minimum cost. The only valid operation are: 
1) Decrement with cost = 1 
2) Delete an element completely from the array with cost = value of element
*/

static int Cost(int[] d) {
    var s = d.Distinct().OrderBy(v => v).ToArray();
    var dp = new int[d.Length,s.Length];
    for (var j = 0 ; j != s.Length ; j++) {
        dp[0, j] = Math.Max(d[0] - s[j], 0);
    }
    for (var i = 1; i != d.Length; i++) {
        for (var j = 0 ; j != s.Length ; j++) {
            dp[i, j] = int.MaxValue;
            var trim = d[i] - s[j];
            if (trim < 0) {
                trim = d[i];
            }
            dp[i, j] = int.MaxValue;
            for (var k = j ; k >= 0 ; k--) {
                dp[i, j] = Math.Min(dp[i, j], dp[i - 1, k] + trim);
            }
        }
    }
    var best = int.MaxValue;
    for (var j = 0 ; j != s.Length ; j++) {
        best = Math.Min(best, dp[d.Length - 1, j]);
    }
    return best;
}
