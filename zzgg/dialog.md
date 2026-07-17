这是更好的收敛。去掉 fashion 后，项目可以专注回答一个更清楚的 NLP 问题：

> **Mem0在多 session 对话中发生错误时，问题主要来自 memory formation、retrieval，还是最终 answer generation？不同memory表示方式会如何影响这些阶段？**

建议项目名称：

> **Where Does Conversational Memory Fail? A Stage-Wise Evaluation of Mem0 on LoCoMo**

## 最终研究问题

可以设置三个 RQ：

- **RQ1:** Mem0与普通 raw-dialogue RAG相比，是否能提高 LoCoMo问答表现？
- **RQ2:** Raw dialogue、LoCoMo observations和 Mem0生成的facts，哪种memory representation更适合检索？
- **RQ3:** 错误主要发生在 memory formation、retrieval还是answer generation？不同问题类型是否表现不同？

## 推荐实验设计

### 1. Oracle诊断

直接把 LoCoMo提供的 gold evidence交给回答模型：

```text
Gold evidence → LLM → Answer
```

这代表回答模型在“检索完全正确”时的表现上限。

如果 gold evidence下仍答错，说明是 reasoning/generation问题，而不是 memory问题。

### 2. Baselines

| 配置 | Memory来源 | Retrieval |
|---|---|---|
| B0 | 最近一个session | 不使用长期检索 |
| B1 | 原始dialogue turns | Dense retrieval |
| B2 | LoCoMo observations | Dense retrieval |
| B3 | LoCoMo session summaries | Dense retrieval |
| M0 | Mem0默认生成的facts | Dense retrieval |
| M1 | 你们调整后的atomic episodic facts | Dense retrieval |

这里先让所有方法使用相同 retriever，避免把 memory表示和retrieval算法混在一起。

### 3. Retrieval实验

选出表现最好的memory representation，然后比较：

- Dense retrieval；
- BM25；
- BM25 + dense hybrid。

这样实验是分阶段的：

```text
第一步：固定retriever，比较memory representation
第二步：固定memory representation，比较retrieval
```

不需要把所有方法做成几十种排列组合。

## 你们修改Mem0的具体内容

不要声称发明新的 temporal memory，而是做一个明确的 extraction ablation：

### Mem0 Default

```text
Caroline moved to Boston.
Caroline accepted a new job.
```

### Atomic Episodic Extraction

```text
[Session 5 | Caroline | moved_to | Boston | Source D127]
[Session 5 | Caroline | accepted | new job | Source D129]
```

抽取规则要求：

- 每条memory只包含一个atomic event；
- 明确保留speaker；
- 保留session和时间；
- 保留source dialogue ID；
- 不把推测当成已确认事实；
- 不把两个事件错误合并；
- 不添加对话中不存在的信息。

你们的结论应写成：

> We study whether atomic, provenance-preserving episodic memories improve retrieval and QA.

而不是：

> We invent episodic memory for Mem0.

## 评估指标

### End-to-end QA

- Answer F1；
- 按 single-hop、multi-hop、temporal、open-domain和adversarial分类报告。

### Retrieval

- Recall@1；
- Recall@5；
- Recall@10；
- MRR，可选。

### Memory formation

抽取一小部分样本人工检查：

- 是否保留关键事实；
- 是否产生hallucinated memory；
- speaker是否正确；
- 时间是否正确；
- 是否保留必要的因果或事件关系。

### 效率

- 每个问题检索的token数；
- ingestion时间；
- retrieval latency，可选。

## 错误分类

最终可以把错误分成：

```text
Formation failure
→ 正确信息没有进入memory

Retrieval failure
→ memory中存在，但未进入top-k

Reasoning failure
→ 正确memory已提供，但答案仍错

Temporal failure
→ 找到了新旧信息，但时间关系判断错误

Multi-hop failure
→ 找到了部分证据，但没有组合完整
```

这会成为项目最重要的分析贡献。

## 三人分工

- 成员一：LoCoMo数据处理、gold evidence oracle、B0/B1 baseline；
- 成员二：Mem0 OSS集成、memory生成、provenance记录；
- 成员三：BM25/dense/hybrid retrieval、统一评估；
- 三人共同：atomic episodic extraction设计和错误分析。

## 对教授的项目描述

> We will build a multi-session conversational agent using Mem0 and evaluate it on LoCoMo. Rather than comparing multiple black-box memory frameworks, we will conduct a controlled, stage-wise study of memory formation, retrieval, and answer generation. We will compare raw dialogue turns, LoCoMo observations and summaries, Mem0’s default memories, and atomic provenance-preserving episodic memories under the same retrieval setup. We will then evaluate retrieval methods and analyze failures across single-hop, multi-hop, and temporal questions.

这个版本不需要自建数据集，也不依赖 fashion应用；它的贡献是**可控的 memory representation实验、阶段性诊断和 LoCoMo错误分析**。这比单纯跑 Mem0 benchmark更完整，也更符合教授原始题目。