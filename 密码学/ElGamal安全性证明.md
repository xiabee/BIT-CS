姓名：肖云杰		学号：1120182349		班级：07111807

#### ElGamal安全性证明

###### 定理：如果 DDH 问题是困难的, ElGamal加密方案在IND-CPA 安全模型下是可证明安全的

证：

* 由于$ElGamal$是公钥加密方案，因此，若它对单个查询时安全的，则它对$q$个查询也是安全的。因此我们假设敌手$A$恰好进行了一次查询。

* 我们假设攻击者攻击$ElGamal$时具有优势$Adv\ \gamma$

* 构建攻击实验$D$如下：

* $Requirement：G,q,g,g^a,g^b,g^z,\\Challenger,Adversary\ \gamma,EI Gamal scheme \prod$

  * 1.挑战者生成公钥$pk=<G,q,g,g^a>$，发送给攻击者$\gamma$
  * 2.攻击者选择希望被加密的明文$m_0,m_1\in G$
  * 3.挑战者随机生成$b$，向攻击者$\gamma$发送$g^b$及挑战密文$Enc(m_b,g^z)(b=0或1)$
  * 4.攻击者$\gamma$判断密文是由哪条明文加密的，如果攻击者认为$b'=b$，则输出$b'=1$，反之输出$0$

* 当$z=rand$时，由于其时均匀随机选择的，所以$\gamma$以$1/2$的概率输出$1$

* 即：$Pr[D(G,q,g,g^a,g^b,g^z)=1]=Pr[Pub\ K^{eav}_{\gamma,\prod}(n)=1]=1/2$

* 当$z=xy$时，此时为$IND-CPA$实验，由于$x,y$是随机选择的，那么攻击者在实验中具有优势$Adv\ \gamma$(假设)：

  $Pr[D(G,q,g,g^a,g^b,g^{ab})=1]=Pr[Pub\ K^{eav}_{\gamma,\prod}(n)=1]=1/2$

* 由于$DDH$在群$G$中式困难的，因此有：

  $Pr[D(G,q,g,g^a,g^b,g^{z})=1]-Pr[D(G,q,g,g^a,g^b,g^{ab})=1]\le negl(n)$

* 即：

  $Adv\ \gamma \le negl(n)$



从而证明了：如果$DDH$问题式困难的，那么$ElGamal$加密方案在$IND-CPA$安全模型下式安全的。