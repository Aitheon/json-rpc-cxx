/*************************************************************************
 * libjson-rpc-cpp
 *************************************************************************
 * @file    unixdomainsocketclient.h
 * @date    11.05.2015
 * @author  Alexandre Poirot <alexandre.poirot@legrand.fr>
 * @license See attached LICENSE.txt
 ************************************************************************/

#ifndef JSONRPC_CPP_UNIXDOMAINSOCKETCLIENT_H_
#define JSONRPC_CPP_UNIXDOMAINSOCKETCLIENT_H_

#include "jsonrpccxx/iclientconnector.hpp"
#include "jsonrpccxx/common.hpp"

namespace jsonrpccxx
{
    class UnixDomainSocketClient : public IClientConnector
    {
        public:
            UnixDomainSocketClient(const std::string& path);
            virtual ~UnixDomainSocketClient();
            virtual void Connect();
            virtual void Disconnect();
            virtual std::string Send(const std::string &request);
            virtual void Notify(const std::string &request);
            void Close();

        private:
            std::string path;
            int socket_fd{-1};
    };

} /* namespace jsonrpc */
#endif /* JSONRPC_CPP_UNIXDOMAINSOCKETCLIENT_H_ */
