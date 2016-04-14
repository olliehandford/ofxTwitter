// =============================================================================
//
// Copyright (c) 2009-2016 Christopher Baker <http://christopherbaker.net>
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
//
// =============================================================================


#pragma once


#include <string>
#include <map>
#include <vector>
#include "Poco/DateTime.h"
#include "Poco/Nullable.h"
#include "ofx/Geo/Coordinate.h"
#include "ofx/Twitter/Entities.h"
#include "ofx/Twitter/Places.h"
#include "ofx/Twitter/Types.h"
#include "ofx/Twitter/User.h"


namespace ofx {
namespace Twitter {


//  https://dev.twitter.com/docs/platform-objects/tweets
class Tweet
{
public:
    class Metadata
    {
    public:
        std::string isoLanguageCode() const;

        /// \todo Would be nice to return SearchRequest::RESULT_TYPE.
        std::string resultType() const;

        static Metadata fromJSON(const ofJson& json);
        
    private:
        std::string _isoLanguageCode;
        std::string _resultType;

    };


    Tweet();
    
    virtual ~Tweet();

    Annotations annotations() const;

    Contributors contributors() const;

    /// \returns coordinates or nullptr if no coordinates are specified.
    const Geo::Coordinate* coordinates() const;

    int64_t id() const;

    Poco::DateTime createdAt() const;

    /// \returns the user or nullptr if no user is specified.
    const User* user() const;

    std::string text() const;

    static Tweet fromJSON(const ofJson& json);

private:
    Annotations _annotations;

    Contributors _contributors;

    /// \brief Optional location data.
    ///
    /// We use a std::shared_ptr to keep track to make it nullable and avoid
    /// the hassle of std::unique_ptr and copies.
    std::shared_ptr<Geo::Coordinate> _coordinates;
    
    Poco::DateTime _createdAt;

    int64_t _utcOffset = 0;

    int64_t _currentUserRetweet = -1;

    Entities _entities;

    int64_t _favoriteCount = -1;

    bool _isQuoteStatus = false;

    int64_t _quotedStatusId = -1;

    /// \brief An optional Tweet.
    ///
    /// We use a std::shared_ptr to keep track to make it nullable and avoid
    /// the hassle of std::unique_ptr and copies.
    std::shared_ptr<Tweet> _quotedStatus;

    bool _favorited = false;

    std::string _filterLevel;

    int64_t _id = -1;

    std::string _inReplyToScreenName;

    int64_t _inReplyToStatusId = -1;

    int64_t _inReplyToUserId = -1;

    std::string _lang;

    bool _possiblySensitive = false;

    // Scopes _scopes;

    int64_t _retweetCount = -1;

    bool _retweeted = false;

    /// \brief An optional Tweet.
    ///
    /// We use a std::shared_ptr to keep track to make it nullable and avoid
    /// the hassle of std::unique_ptr and copies.
    std::shared_ptr<Tweet> _retweetedStatus;

    std::string _source;

    std::string _text;

    bool _truncated = false;

    /// \brief Optional user data.
    ///
    /// We use a std::shared_ptr to keep track to make it nullable and avoid
    /// the hassle of std::unique_ptr and copies.
    std::shared_ptr<User> _user;

    bool _withheldCopyright;

    /// \brief Optional user data.
    ///
    /// We use a std::shared_ptr to keep track to make it nullable and avoid
    /// the hassle of std::unique_ptr and copies.
    std::shared_ptr<Places> _places;

    Metadata _metadata;
};


} } // namespace ofx::Twitter
