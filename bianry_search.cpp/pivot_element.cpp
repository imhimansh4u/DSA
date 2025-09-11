// int search(vector<int>& arr, int n, int k)
// {
//     // Write your code here.
//     // Return the position of K in ARR else return -1.
//     int s = 0;
//     int e = arr.size()-1;
//     int mid = s + (e-s)/2;
//     int pivot = -1;
//     while(s<e){
//         if(arr[0] < arr[arr.size()-1]){
//             break;
//         }
//         else{
//             if(arr[0] <= arr[mid]){
//                 s = mid+1;
//             } else {
//                 e = mid;
//             }
//             mid = s + (e - s) / 2;
//         }
//     }
//     pivot = s; 
//     e = arr.size()-1; 
//     while(s<e){
//         if(k>=pivot){
//             mid  = pivot + (e-pivot)/2;
//             if(arr[mid] == k){
//                 return mid;
//             }
//             else if(arr[mid] < k){
//                 pivot = mid +1;
//             }
//             else{
//                 e = mid-1;
//             }
//         }
//         else{
//             s = 0;
//             e = pivot-1;
//             mid = s + (e-s)/2;
//             if(arr[mid] == k){
//                 return mid;
//             }
//             else if(arr[mid]<k){
//                 s = mid +1;
//             }
//             else{
//                 e = mid-1;
//             }
//         }
//     }
//     return -1;
// }
