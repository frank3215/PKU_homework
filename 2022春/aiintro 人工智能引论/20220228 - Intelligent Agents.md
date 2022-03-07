# Intelligent Agents - 2022.2.28

## 1. 对下述断言，请判断真假并给出解释或支持实例

### 1) 一个 Agent 只能感知状态的部分信息，那么它不可能是完美理性的.

否。例如《Artificial Intelligence: A Modern Approach》给出的扫地机器人模型，它即使只能感知到自己的位置的地板是否是脏的（只能感知状态的部分信息），却依然可以证明在给出的条件下是完美理性的。（见Exercise 2.2）

### 2) Agent 程序与 Agent 函数的输入是相同的.

否。Agent程序接受的输入是当前环境的状态，而Agent函数接受的输入是所有历史环境状态的序列。

### 3) 在不可观测的环境中，每个 Agent 都是理性的.

否。还是《Artificial Intelligence: A Modern Approach》扫地机器人的例子。在什么都观测不到的环境中，这个扫地机器人如果什么都不做，在书中给出的衡量标准下毫无疑问是不理性的。即使是随机进行扫地、任意选择一个方向移动的机器人都比这个机器人有理性。

### 4) 一个完美理性的玩扑克 Agent 是不可能输的.

否。扑克有随机因素：

1. 可能存在对任何可能的操作都不可能获胜的局面。
2. Agent理性的衡量标准是获胜的**期望**概率最大，而不保证对所有局面都能获胜。因此，可能存在在某个Agent函数下导致Agent输的局面。

## 2. 请写出基于目标的 Agent 的伪代码 Agent 程序

__function__ GOAL-BASED-AGENT(_percept_) __returns__ an action  
&emsp;__persistent__: _state_, the agent's current conception of the world state  
&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;_model_, a description of how the next state depends on current state and action  
&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;_action_, the most recent action, initially none
&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;_actions_, all possible actions

&emsp;_state_ &larr; UPDATE-STATE(_state_, _action_, _percept_, _model_)  
&emsp;_best_action_ &larr; **best** *action* **in** _actions_ **such that** EXPECTED-VALUE(UPDATE-STATE(_state_, _action_, _percept_, _model_)) **is maximized**
&emsp;__return__ _best_action_  
