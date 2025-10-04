   int n = temperatures.size();
    vector<int> answer(n, 0);
    stack<int> st; // stores indices

    for (int i = n - 1; i >= 0; --i) {
        while (!st.empty() && temperatures[st.top()] <= temperatures[i]) {
            st.pop();
        }
        if (!st.empty()) {
            answer[i] = st.top() - i;
        }
        st.push(i);
    }

    return answer;