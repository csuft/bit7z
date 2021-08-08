/*
 * bit7z - A C++ static library to interface with the 7-zip DLLs.
 * Copyright (c) 2014-2021  Riccardo Ostani - All Rights Reserved.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * Bit7z is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with bit7z; if not, see https://www.gnu.org/licenses/.
 */

#ifndef STDSTREAMITEM_HPP
#define STDSTREAMITEM_HPP

#include "internal/genericstreamitem.hpp"

namespace bit7z {
    using std::istream;

    class StdStreamItem final : public GenericStreamItem {
        public:
            explicit StdStreamItem( istream& stream, const tstring& path );

            tstring name() const override;

            bool isDir() const noexcept override;

            uint64_t size() const override;

            FILETIME creationTime() const noexcept override;

            FILETIME lastAccessTime() const noexcept override;

            FILETIME lastWriteTime() const noexcept override;

            uint32_t attributes() const noexcept override;

            tstring path() const override;

            fs::path inArchivePath() const override;

            HRESULT getStream( ISequentialInStream** inStream ) const override;

        private:
            istream& mStream;
            const fs::path mStreamPath;
    };
}

#endif //STDSTREAMITEM_HPP