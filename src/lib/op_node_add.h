/**
 *	op_node_add.h
 *
 *	@author	Masaki Fujimoto <fujimoto@php.net>
 *
 *	$Id$
 */
#ifndef	__OP_NODE_ADD_H__
#define	__OP_NODE_ADD_H__

#include "op.h"
#include "cluster.h"

using namespace std;
using namespace boost;

namespace gree {
namespace flare {

/**
 *	opcode class (node_add)
 */
class op_node_add : public op {
protected:
	cluster*	_cluster;

	string		_node_server_name;
	int				_node_server_port;

public:
	op_node_add(shared_connection c, cluster* cl);
	virtual ~op_node_add();

	virtual int run_client(vector<cluster::node>& v);

protected:
	virtual int _parse_text_server_parameters();
	virtual int _run_server();
	virtual int _run_client();
	virtual int _parse_text_client_parameters(vector<cluster::node>& v);
};

}	// namespace flare
}	// namespace gree

#endif	// __OP_NODE_ADD_H__
// vim: foldmethod=marker tabstop=2 shiftwidth=2 autoindent
