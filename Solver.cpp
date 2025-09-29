//
// void dfs(int row, int col, Dict::Node* currNode, std::string& currPrefix,
//          std::string board[2][3], std::set<FoundWord> &wordsFound, std::vector<std::pair<int, int>> &currPath) {
//     // bounds
//     if (row < 0 || col < 0) return;
//     if (row >= 2 || col >= 3) return; 
//
//     // "*" means cell is visited
//     if (board[row][col] == "*") return;
//
//     std::string cellStr = board[row][col];
//     Dict::Node* next = currNode;
//
//     for (char ch : cellStr) {
//         int idx = ch - 'a';
//         if (idx < 0 || idx >= 26) return;
//         next = next->letterPointers[idx];
//         if (!next) return;  // ex: ensures both "q" and "u" are in path for "qu"
//     }
//     board[row][col] = "*";  // mark visited
//
//     currPath.emplace_back(row, col);
//     currPrefix += cellStr;
//
//     if (next->isWord) {
//         // wordsFound.insert(currPrefix);
//         wordsFound.insert(FoundWord(currPrefix, next->definition, currPath));
//     }
//
//     dfs(row - 1, col, next, currPrefix, board, wordsFound, currPath); 
//     dfs(row - 1, col + 1, next, currPrefix, board, wordsFound, currPath); 
//     dfs(row, col + 1, next, currPrefix, board, wordsFound, currPath);    
//     dfs(row + 1, col + 1, next, currPrefix, board, wordsFound, currPath);
//     dfs(row + 1, col, next, currPrefix, board, wordsFound, currPath);   
//     dfs(row + 1, col - 1, next, currPrefix, board, wordsFound, currPath);
//     dfs(row, col - 1, next, currPrefix, board, wordsFound, currPath);   
//     dfs(row - 1, col - 1, next, currPrefix, board, wordsFound, currPath);
//
//     // backtrack
//     currPrefix.resize(currPrefix.size() - cellStr.size());
//     currPath.pop_back();
//     board[row][col] = cellStr; 
// }
