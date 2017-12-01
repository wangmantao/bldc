# bldc
bldc for fan
## 建立Git环境，可多处编译并提交，所有平台保持代码同步
### git 基本用法
* git add ---要添加git仓库的文件
* git commit -m "dajfeasjdfe" --- 本次提交文件的说明
* git stauts / git diff 	--- 可以看到本地git管理下的文件状态。并且可s查看文件的历史变更具体不同点。

总结： 在持续的文件编辑下，在某次修改、编辑后想在此打一个Mark，表示这次主要完成的一个什么目的。就用"git add 文件名" & "git commit -m 'mark内容'"，这样的话，将来用"git log" 就可以看到每次完成任务的mark。

* git log	--- 查看提交的历史
* git reset --hard HEAD^	--- 版本回退  
* git reflog 	---查看命令的历史

配置相关： 本地的git总要与远程服务器保持同步，所以要配置关于committer的远程相关的账号。

* git config --global --edit	---编辑配置文件
* git commit --amend --reset-author	---配置完后，修改本次提交所使用的用户身份

